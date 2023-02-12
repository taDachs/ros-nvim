local util = require("mutils")
local string = require("string")
local config = require("ros-nvim.config")

local ros = {}

ros._package_list = nil
ros._srv_list = {}
ros._msg_list = {}

ros.Package = {}
ros.Package.__index = ros.Package

function ros.Package.new(name, path, files)
  local self = setmetatable({}, ros.Package)
  self.name = name
  self.path = path
  self.files = files
  return self
end

ros.Message = {}
ros.Message.__index = ros.Message

function ros.Message.new(name, definition, package)
  local self = setmetatable({}, ros.Message)
  self.name = name
  self.definition = definition
  self.package = package
  return self
end

ros.Service = {}
ros.Service.__index = ros.Service

function ros.Service.new(name, definition, package)
  local self = setmetatable({}, ros.Service)
  self.name = name
  self.definition = definition
  self.package = package
  return self
end

function ros.is_ros_sourced()
  return os.getenv("ROS_VERSION") ~= nil
end

function ros.get_ros_package_path()
  if ros._ros_package_path ~= nil then
    return ros._ros_package_path
  end
  local pkg_paths = io.popen("bash -c 'source " .. ros.get_ws_dir() .. "/devel/setup.bash; echo $ROS_PACKAGE_PATH'")
    :read("*all")
  pkg_paths = string.gsub(pkg_paths, "\n$", "")
  ros._ros_package_path = pkg_paths
  return pkg_paths
end

function ros.get_ws_dir()
  if ros._ws_dir ~= nil then
    return ros._ws_dir
  end
  if not ros.is_ros_sourced() then
    return nil
  end
  local cmake_prefix_path = os.getenv("CMAKE_PREFIX_PATH")
  if cmake_prefix_path == nil then
    return nil
  end

  -- first element in cmake_prefix_path should be last sourced ws
  local ws_dir = util.get_dirname(util.strsplit(cmake_prefix_path, ":")[1])
  ros._ws_dir = ws_dir
  return ws_dir
end

function ros.get_package_list()
  if ros._package_list ~= nil then
    return ros._package_list
  end

  if ros.is_ros_sourced() then
    ros.source_ws()
  else
    ros._package_list = {}
  end

  return ros._package_list
end

local function prefix_command_with_pkg_path(command)
  return "ROS_PACKAGE_PATH=" .. ros.get_ros_package_path() .. " " .. command
end

function ros.source_ws()
  ros._package_list = {}
  ros._msg_list = {}
  ros._srv_list = {}
  ros._ros_package_path = nil
  ros._ws_dir = nil
  ros._telescope_result_list = nil

  local pkg_paths = io.popen(prefix_command_with_pkg_path("rospack list")):read("*all")
  for _, path in pairs(util.strsplit(pkg_paths, "\n")) do
    path = util.strsplit(path)
    local name, pkg_path = path[1], path[2]
    if not config.only_workspace or util.is_subdir(pkg_path, ros.get_ws_dir()) then
      local files = util.find_files_in_dir(pkg_path, "f")
      ros._package_list[name] = ros.Package.new(name, pkg_path, files)
    end
  end
end

function ros.get_package_path(pkg_name)
  local pkg_path = io.popen(prefix_command_with_pkg_path("rospack find " .. pkg_name)):read("*all")
  pkg_path = string.gsub(pkg_path, "\n$", "")
  return pkg_path
end

function ros.get_msg_definition(msg_name, pkg)
  if ros._msg_list[msg_name] ~= nil then
    return ros._msg_list[msg_name].definition
  end
  if pkg ~= nil then
    msg_name = pkg .. "/" .. msg_name
  end
  local definition = io.popen(prefix_command_with_pkg_path("rosmsg show " .. msg_name .. " 2> /dev/null")):read("*all")
  if string.len(definition) == 0 then
    return nil
  else
    ros._msg_list[msg_name] = ros.Message.new(msg_name, definition, pkg)
    return definition
  end
end

function ros.get_srv_definition(srv_name, pkg)
  if pkg ~= nil then
    srv_name = pkg .. "/" .. srv_name
  end
  if ros._srv_list[srv_name] ~= nil then
    return ros._srv_list[srv_name].definition
  end
  local definition = io.popen(prefix_command_with_pkg_path("rossrv show " .. srv_name .. " 2> /dev/null")):read("*all")
  if string.len(definition) == 0 then
    return nil
  else
    ros._srv_list[srv_name] = ros.Service.new(srv_name, definition, pkg)
    return definition
  end
end

local function create_floating_window(content)
  local w, h = 50, #content

  local buf = vim.api.nvim_create_buf(false, true)
  local cursor = vim.api.nvim_win_get_cursor(0)
  local y, x = cursor[1], cursor[2]
  local ui = vim.api.nvim_list_uis()[1]

  local opts = {
    relative = "cursor",
    width = w,
    height = h,
    col = 0,
    row = 1,
    anchor = "NW",
    style = "minimal",
    focusable = false,
  }
  local win = vim.api.nvim_open_win(buf, false, opts)

  vim.api.nvim_buf_set_lines(buf, 0, -1, false, content)
  local autocmd = vim.api.nvim_create_autocmd({ "CursorMoved" }, {
    callback = function()
      vim.api.nvim_win_close(win, true)
    end,
    buffer = 0,
    once = true,
  })
end

function ros.show_message_definition()
  -- Get the current visual selection
  local cursor_word = vim.fn.expand("<cWORD>")
  -- Test String: PointCloud2
  -- Test String: sensor_msgs::PointCloud2

  local pkg, msg
  local val = util.strsplit(cursor_word, "::")
  if #val >= 2 then
    pkg = val[1]
    msg = val[2]
  else
    pkg = nil
    msg = val[1]
  end

  local definition = ros.get_msg_definition(msg, pkg)

  if definition == nil then
    vim.notify("No valid message: " .. cursor_word)
    return
  end

  definition = util.strsplit(definition, "\n")
  create_floating_window(definition)
end

function ros.show_service_definition()
  -- Get the current visual selection
  local cursor_word = vim.fn.expand("<cWORD>")
  -- Test String: Trigger
  -- Test String: std_srvs::Trigger

  local pkg, srv
  local val = util.strsplit(cursor_word, "::")
  if #val >= 2 then
    pkg = val[1]
    srv = val[2]
  else
    pkg = nil
    srv = val[1]
  end

  local definition = ros.get_srv_definition(srv, pkg)

  if definition == nil then
    vim.notify("No valid service: " .. cursor_word)
    return
  end

  definition = util.strsplit(definition, "\n")
  create_floating_window(definition)
end

function ros.open_launch_include()
  -- Get the current visual selection
  vim.cmd('normal "vya"')
  local visual_selection = vim.fn.getreg("v")

  local regex = "$%(find ([%a%d_]+)%)(/[%a%d_%.%~/-]+)"

  -- Test string: <include file="$(find biobots_husky_sim)/launch/gazebo.xml.launch"/>
  local package, file = string.match(visual_selection, regex)

  if package and file then
    local output = ros.get_package_path(package)
    local path = output .. file
    vim.cmd("edit " .. path)
  end
end

function ros.rosed(pkg_name, file_name, edit_command)
  local pkg = ros.get_package_list()[pkg_name]
  if pkg == nil then
    vim.notify('"' .. pkg_name .. '" does not exist')
    return
  end

  local pkg_files = pkg.files

  if not edit_command then
    edit_command = "edit"
  end

  for _, f in pairs(pkg_files) do
    if util.get_basename(f) == file_name then -- found file
      vim.cmd(edit_command .. " " .. f)
      return
    end
  end

  -- file does not exist
  vim.notify('"' .. file_name .. '" does not exist in package "' .. pkg_name .. '"')
end

function ros.package_file_completion(arg_lead, cmd_line, cursor_pos)
  cmd_line = string.sub(cmd_line, 1, string.len(cmd_line) - string.len(arg_lead))
  local args = util.strsplit(cmd_line)
  if #args == 1 then -- only command
    return util.keys(ros.get_package_list())
  elseif #args == 2 then -- command and first arg
    local pkg = ros.get_package_list()[args[2]]

    if pkg ~= nil then
      return util.map(pkg.files, util.get_basename)
    else
      return {}
    end
  end
end

return ros
