local scan = require("plenary.scandir")

PackageListing = {}
PackageListing.__index = PackageListing

function PackageListing.new(name, path)
  local self = setmetatable({}, PackageListing)
  self.name = name
  self.path = path
  return self
end

IROSShellEnvironment = {}
IROSShellEnvironment.__index = IROSShellEnvironment

function IROSShellEnvironment:new(o)
  o = o or {}
  setmetatable(o, self)
  self.__index = self
  return o
end

function IROSShellEnvironment:build_set_vars()
  local set_vars = {}
  for k, v in pairs(self.env) do
    if v ~= nil then
      table.insert(set_vars, "export " .. k .. "=" .. v)
    end
  end
  return table.concat(set_vars, ";")
end

function IROSShellEnvironment:build_get_vars()
  local get_vars = {}
  for k, _ in pairs(self.env) do
    table.insert(get_vars, "echo " .. k .. "=$" .. k)
  end
  return table.concat(get_vars, ";")
end

function IROSShellEnvironment:source_ws(ws_path)
  local set_vars = self:build_set_vars()
  local get_vars = self:build_get_vars()

  local source_command = "source " .. ws_path .. "/setup.bash"
  local command = { set_vars, source_command, get_vars }
  local command_string = "bash -c '" .. table.concat(command, ";") .. "'"

  local result = vim.fn.system(command_string)

  for _, line in pairs(vim.fn.split(result, "\n")) do
    line = vim.fn.split(line, "=")
    local k, v = line[1], line[2]
    self.env[k] = v
  end
end

function IROSShellEnvironment:run_command(command)
  local set_vars = self:build_set_vars()

  local command_string = "bash -c '" .. set_vars .. ";" .. command .. "'"
  return vim.fn.system(command_string)
end

function IROSShellEnvironment:list_packages()
  local pkgs = {}

  for _, root in pairs(self:get_source_dirs()) do
    for _, xml_path in
      pairs(scan.scan_dir(root, { hidden = false, add_dirs = false, search_pattern = [[package%.xml$]] }))
    do
      local pkg_path = vim.fn.resolve(vim.fs.normalize(vim.fs.dirname(xml_path)))
      local pkg_name = vim.fs.basename(pkg_path)

      local xml_content = vim.fn.readfile(xml_path)
      for _, line in pairs(xml_content) do
        local name = string.match(line, [[<name>(.*)</name>]])
        if name ~= nil then
          pkg_name = name
          break
        end
      end

      if pkgs[pkg_name] == nil then
        pkgs[pkg_name] = PackageListing.new(pkg_name, pkg_path)
      end
    end
  end

  return vim.tbl_values(pkgs)
end

ROS1ShellEnvironment = IROSShellEnvironment:new()
ROS1ShellEnvironment.__index = ROS1ShellEnvironment

function ROS1ShellEnvironment.new()
  local self = setmetatable({}, ROS1ShellEnvironment)
  self.env = {}
  self.env.PATH = os.getenv("PATH") or ""
  self.env.CMAKE_PREFIX_PATH = os.getenv("CMAKE_PREFIX_PATH") or ""
  self.env.LD_LIBRARY_PATH = os.getenv("LD_LIBRARY_PATH") or ""
  self.env.PKG_CONFIG_PATH = os.getenv("PKG_CONFIG_PATH") or ""
  self.env.PYTHONPATH = os.getenv("PYTHONPATH") or ""
  self.env.ROS_DISTRO = os.getenv("ROS_DISTRO") or ""
  self.env.ROS_ETC_DIR = os.getenv("ROS_ETC_DIR") or ""
  self.env.ROS_PACKAGE_PATH = os.getenv("ROS_PACKAGE_PATH") or ""
  self.env.ROS_PYTHON_VERSION = os.getenv("ROS_PYTHON_VERSION") or ""
  self.env.ROS_VERSION = os.getenv("ROS_VERSION") or ""
  self.env.ROS_ROOT = os.getenv("ROS_ROOT") or ""
  self.env.ROS_MASTER_URI = os.getenv("ROS_MASTER_URI") or ""
  self.env.ROSLISP_PACKAGE_DIRECTORIES = os.getenv("ROSLISP_PACKAGE_DIRECTORIES") or ""
  return self
end

function ROS1ShellEnvironment:is_sourced()
  return self.env.ROS_VERSION ~= ""
end

function ROS1ShellEnvironment:get_current_ws()
  if self.env.CMAKE_PREFIX_PATH == "" then
    return nil
  end
  local ws_path = vim.fn.split(self.env.CMAKE_PREFIX_PATH, ":")[1]
  return ws_path
end

function ROS1ShellEnvironment:get_source_dirs()
  if self.env.CMAKE_PREFIX_PATH == "" then
    return {}
  end
  local ws_paths = vim.fn.split(self.env.CMAKE_PREFIX_PATH, ":")
  local source_dirs = vim.tbl_map(function(x)
    x = vim.fn.resolve(vim.fs.normalize(x))
    local opt_ros = "/opt/ros"
    if string.sub(x, 1, string.len(opt_ros)) == opt_ros then
      return x .. "/share"
    else
      return vim.fs.dirname(x) .. "/src"
    end
  end, ws_paths)
  return source_dirs
end

ROS2ShellEnvironment = IROSShellEnvironment:new()
ROS2ShellEnvironment.__index = ROS2ShellEnvironment

function ROS2ShellEnvironment.new()
  local self = setmetatable({}, ROS2ShellEnvironment)
  self.env = {}
  self.env.PATH = os.getenv("PATH") or ""
  self.env.AMENT_PREFIX_PATH = os.getenv("AMENT_PREFIX_PATH") or ""
  self.env.PYTHONPATH = os.getenv("PYTHONPATH") or ""
  self.env.LD_LIBRARY_PATH = os.getenv("LD_LIBRARY_PATH") or ""
  self.env.ROS_DISTRO = os.getenv("ROS_DISTRO") or ""
  self.env.ROS_PYTHON_VERSION = os.getenv("ROS_PYTHON_VERSION") or ""
  self.env.ROS_VERSION = os.getenv("ROS_VERSION") or ""
  self.env.COLCON_PREFIX_PATH = os.getenv("COLCON_PREFIX_PATH") or ""
  self.env.CMAKE_PREFIX_PATH = os.getenv("CMAKE_PREFIX_PATH") or ""
  return self
end

function ROS2ShellEnvironment:is_sourced()
  return self.env.ROS_VERSION ~= ""
end

function ROS2ShellEnvironment:get_current_ws()
  if self.env.AMENT_PREFIX_PATH == "" then
    return nil
  end
  local ws_path = self:_get_ws_root(vim.fn.split(self.env.AMENT_PREFIX_PATH, ":")[1], false)
  return ws_path
end

function ROS2ShellEnvironment:_get_ws_root(path, add_source_dir)
  if add_source_dir == nil then
    add_source_dir = false
  end

  local opt_ros = "/opt/ros"

  paths = {}
  table.insert(paths, path)
  for p in vim.fs.parents(path) do
    table.insert(paths, p)
  end

  for _, p in pairs(paths) do
    p = vim.fn.resolve(vim.fs.normalize(p))
    if p == opt_ros then
      if add_source_dir then
        path = path .. "/share"
      end
      return path
    end

    if vim.fs.basename(p) == "install" and vim.fn.isdirectory(p) then
      if add_source_dir then
        p = vim.fs.dirname(p) .. "/src"
      end
      return p
    end
  end
end

function ROS2ShellEnvironment:get_source_dirs()
  if self.env.AMENT_PREFIX_PATH == "" then
    return {}
  end
  local ws_paths = vim.fn.split(self.env.AMENT_PREFIX_PATH, ":")
  local source_dirs = {}
  for _, path in pairs(ws_paths) do
    local p = self:_get_ws_root(path, true)
    if not vim.tbl_contains(source_dirs, p) then
      table.insert(source_dirs, p)
    end
  end

  return source_dirs
end

M = {}
M.ROS1ShellEnvironment = ROS1ShellEnvironment
M.ROS2ShellEnvironment = ROS2ShellEnvironment
M.PackageListing = PackageListing

return M
