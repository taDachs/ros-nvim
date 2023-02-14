local util = require("mutils")
local ros_cli = require("ros-nvim.ros_cli")

Package = {}
Package.__index = Package

Package.GLOBAL_WS = "global"
Package.USER_WS = "user_ws"
Package.CURRENT_WS = "current"

function Package.new(name, path, files, dirs, msgs, srvs, ws_type)
  if msgs == nil then
    msgs = {}
  end
  if srvs == nil then
    srvs = {}
  end
  if files == nil then
    files = {}
  end
  if dirs == nil then
    dirs = {}
  end
  if ws_type == nil then
    ws_type = Package.GLOBAL_WS
  end

  local self = setmetatable({}, Package)
  self.name = name
  self.path = path
  self.files = files
  self.dirs = dirs
  self.msgs = msgs
  self.srvs = srvs
  -- either "global", "user_ws", or "current"
  -- global means installed under /opt/ros/noetic/share
  -- user_ws means a workspace, but not the currently sourced one
  -- current means the current workspace
  self.ws_type = ws_type
  return self
end

function Package.from_path(name, path, ws_type)
  local files = util.find_files_in_dir(path, "f")
  local dirs = util.filter(util.find_files_in_dir(path, "d"), function(p)
    return p ~= path
  end)

  local srvs = {}
  local msgs = {}
  for _, file in pairs(files) do
    if string.match(file, "%.msg$") then
      local msg = Message.from_file(file, name)
      msgs[msg.name] = msg
    elseif string.match(file, "%.srv$") then
      local srv = Service.from_file(file, name)
      srvs[srv.name] = srv
    end
  end

  local pkg = Package.new(name, path, files, dirs, msgs, srvs, ws_type)
  return pkg
end

function Package:contains_msg(name)
  return self.msgs[name] ~= nil
end

function Package:get_msg(name)
  return self.msgs[name]
end

function Package:contains_srv(name)
  return self.srvs[name] ~= nil
end

function Package:get_srv(name)
  return self.srvs[name]
end

Message = {}
Message.__index = Message

function Message.new(name, definition, package)
  local self = setmetatable({}, Message)
  self.name = name
  self.definition = definition
  self.package = package
  return self
end

function Message.from_file(path, package)
  local definition = util.read_file(path)
  local name = util.get_basename(path)
  name = util.strsplit(name, "%.")[1]
  return Message.new(name, definition, package)
end

Service = {}
Service.__index = Service

function Service.new(name, definition, package)
  local self = setmetatable({}, Service)
  self.name = name
  self.definition = definition
  self.package = package
  return self
end

function Service.from_file(path, package)
  local definition = util.read_file(path)
  local name = util.get_basename(path)
  name = util.strsplit(name, "%.")[1]
  return Service.new(name, definition, package)
end

RosHandle = {}
RosHandle.__index = RosHandle

function RosHandle.new(ros_version)
  if ros_version == nil then
    ros_version = 1
  end
  local self = setmetatable({}, RosHandle)
  self.pkgs = {}
  if ros_version == 1 then
    self.env = ros_cli.ROS1ShellEnvironment.new()
  else
    error("ROS2ShellEnvironment not yet implemented")
    return
  end
  return self
end

function RosHandle:is_initialized()
  return util.len(self.pkgs) > 0
end

function RosHandle:get_pkg(name)
  -- package not yet loaded
  if type(self.pkgs[name]) == "string" then
    local ws_path = self.env:get_current_ws()
    local pkg_path = self.pkgs[name]

    local ws_type = Package.USER_WS
    if util.is_subdir(pkg_path, "/opt/ros") then
      ws_type = Package.GLOBAL_WS
    elseif util.is_subdir(pkg_path, util.get_dirname(ws_path)) then
      ws_type = Package.CURRENT_WS
    end

    self.pkgs[name] = Package.from_path(name, pkg_path, ws_type)
  end

  return self.pkgs[name]
end

function RosHandle:list_pkg_names()
  return util.keys(self.pkgs)
end

function RosHandle:source_ws(ws_path)
  if ws_path == nil then
    local current_ws = self.env:get_current_ws()
    if current_ws == nil then
      return
    end
    ws_path = current_ws
  end

  self.env:source_ws(ws_path)

  local pkg_listings = self.env:list_packages()

  self.pkgs = {}

  for _, pkg_listing in pairs(pkg_listings) do
    self.pkgs[pkg_listing.name] = pkg_listing.path
  end
end

function RosHandle:get_msg(msg_name, pkg_name)
  if pkg_name ~= nil then
    local pkg = self:get_pkg(pkg_name)
    if pkg ~= nil and pkg:contains_msg(msg_name) then
      return pkg:get_msg(msg_name)
    end
  end

  for k, _ in pairs(self.pkgs) do
    local pkg = self:get_pkg(k)
    if pkg:contains_msg(msg_name) then
      return pkg:get_msg(msg_name)
    end
  end

  return nil
end

function RosHandle:get_srv(srv_name, pkg_name)
  if pkg_name ~= nil then
    local pkg = self:get_pkg(pkg_name)
    if pkg ~= nil and pkg:contains_srv(srv_name) then
      return pkg:get_srv(srv_name)
    end
  end

  for k, _ in pairs(self.pkgs) do
    local pkg = self:get_pkg(k)
    if pkg:contains_srv(srv_name) then
      return pkg:get_srv(srv_name)
    end
  end

  return nil
end

function RosHandle:get_current_ws()
  return self.env:get_current_ws()
end

M = {}
M.RosHandle = RosHandle
M.Message = Message
M.Service = Service
M.Package = Package

return M
