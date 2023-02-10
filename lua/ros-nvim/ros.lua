local util = require("mutils")
local string = require("string")
local config = require("ros-nvim.config")

local ros = {}

ros.Package = {}
ros.Package.__index = ros.Package

ros._package_list = nil

function ros.Package.new(name, path, files)
  local self = setmetatable({}, ros.Package)
  self.name = name
  self.path = path
  self.files = files
  return self
end

function ros.is_ros_sourced()
  return os.getenv("ROS_VERSION") ~= nil
end

function ros.get_package_list()
  if ros._package_list ~= nil then return ros._package_list end

  if ros.is_ros_sourced() then
    ros.init_package_list(config.only_workspace)
  else
    ros._package_list = {}
  end

  return ros._package_list
end

function ros.init_package_list(only_workspace)
  ros._package_list = {}
  local pkg_paths = io.popen("rospack list"):read('*all')
  for _, path in pairs(util.strsplit(pkg_paths, "\n")) do
    path = util.strsplit(path)
    local name, pkg_path = path[1], path[2]
    if only_workspace and string.match(pkg_path, "^/opt/.*") then
      goto continue
    end
    local files = util.find_files_in_dir(pkg_path, "f")
    ros._package_list[name] = ros.Package.new(name, pkg_path, files)

    ::continue::
  end
end

local function get_package_path(pkg_name)
  local pkg_path = io.popen("rospack find " .. pkg_name):read('*all')
  pkg_path = string.gsub(pkg_path, "\n$", "")
  return pkg_path
end

function ros.open_launch_include()
  -- Get the current visual selection
  vim.cmd('normal "vya"')
  local visual_selection = vim.fn.getreg('v')

  local regex = "$%(find ([%a%d_]+)%)(/[%a%d_%.%~/-]+)"

  -- Test string: <include file="$(find biobots_husky_sim)/launch/gazebo.xml.launch"/>
  local package, file = string.match(visual_selection, regex)

  if package and file then
    -- Open the file "foo"
    local output = get_package_path(package)
    local path = output..file
    vim.cmd('edit ' .. path)
  end
end

function ros.rosed(pkg_name, file_name, edit_command)
  local pkg = ros.get_package_list()[pkg_name]
  if pkg == nil then
    vim.notify("\"" .. pkg_name .. "\" does not exist")
    return
  end

  local pkg_files = pkg.files

  if not edit_command then
    edit_command = "edit"
  end

  for _, f in pairs(pkg_files) do
    if util.get_basename(f) == file_name then  -- found file
      vim.cmd(edit_command .. " " .. f)
      return
    end
  end

  -- file does not exist
  vim.notify("\"" .. file_name .. "\" does not exist in package \"" .. pkg_name .. "\"")
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
