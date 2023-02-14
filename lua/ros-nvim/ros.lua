local config = require("ros-nvim.config")
local ros_handle = require("ros-nvim.ros_handle")
local util = require("mutils")

local ros = {}

ros.handle = ros_handle.RosHandle.new()

-- does a include b
function ros.ws_type_includes(a, b)
  if a == ros_handle.Package.GLOBAL_WS then
    return true
  end

  if a == ros_handle.Package.USER_WS and b ~= ros_handle.Package.GLOBAL_WS then
    return true
  end

  -- only if both are current
  return a == b
end

local function create_floating_window(content)
  local w, h = 50, #content

  local buf = vim.api.nvim_create_buf(false, true)

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
  vim.api.nvim_buf_call(buf, function()
    vim.cmd("setf ros")
  end)
  vim.api.nvim_create_autocmd({ "CursorMoved" }, {
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

  local pkg_name, msg_name
  local val = util.strsplit(cursor_word, "::")
  if #val >= 2 then
    pkg_name = val[1]
    msg_name = val[2]
  else
    pkg_name = nil
    msg_name = val[1]
  end

  local msg = ros.handle:get_msg(msg_name, pkg_name)

  if msg == nil then
    vim.notify("No valid message: " .. cursor_word)
    return
  end

  local lines = {}
  for _, line in pairs(util.strsplit(msg.definition, "\n")) do
    -- filter comments
    if not string.match(line, "^%s*#") then
      local filtered = string.gsub(line, "#.*$", "")
      table.insert(lines, filtered)
    end
  end
  create_floating_window(lines)
end

function ros.show_service_definition()
  -- source if not already done
  if not ros.handle:is_initialized() then
    ros.handle:source_ws()
  end

  -- Get the current visual selection
  local cursor_word = vim.fn.expand("<cWORD>")
  -- Test String: Trigger
  -- Test String: std_srvs::Trigger

  local pkg_name, srv_name
  local val = util.strsplit(cursor_word, "::")
  if #val >= 2 then
    pkg_name = val[1]
    srv_name = val[2]
  else
    pkg_name = nil
    srv_name = val[1]
  end

  local srv = ros.handle:get_srv(srv_name, pkg_name)

  if srv == nil then
    vim.notify("No valid service: " .. cursor_word)
    return
  end

  local lines = {}
  for _, line in pairs(util.strsplit(srv.definition, "\n")) do
    -- filter comments
    if not string.match(line, "^%s*#") then
      local filtered = string.gsub(line, "#.*$", "")
      table.insert(lines, filtered)
    end
  end
  create_floating_window(lines)
end

function ros.open_launch_include()
  -- source if not already done
  if not ros.handle:is_initialized() then
    ros.handle:source_ws()
  end

  -- Get the current visual selection
  vim.cmd('normal "vya"')
  local visual_selection = vim.fn.getreg("v")

  local regex = "$%(find ([%a%d_]+)%)(/[%a%d_%.%~/-]+)"

  -- Test string: <include file="$(find biobots_husky_sim)/launch/gazebo.xml.launch"/>
  local pkg_name, file = string.match(visual_selection, regex)

  if pkg_name and file then
    local pkg = ros.handle:get_pkg(pkg_name)
    if pkg == nil then
      error("Package " .. pkg_name .. " doesn't exist")
    end
    local path = pkg.path .. "/" .. file
    vim.cmd("edit " .. path)
  end
end

function ros.rosed(pkg_name, file_name, edit_command)
  -- source if not already done
  if not ros.handle:is_initialized() then
    ros.handle:source_ws()
  end

  local pkg = ros.handle:get_pkg(pkg_name)
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

function ros.rossource(ws_path)
  local current_ws_path = ros.handle:get_current_ws()

  if current_ws_path == nil and ws_path == nil then
    vim.notify("No workspace path given and no previously sourced workspaces")
    return
  end

  ros.handle:source_ws(ws_path)

  local new_ws_path = ros.handle:get_current_ws()
  vim.notify("Sourced workspace: " .. new_ws_path)
end

function ros.roscd(pkg_path)
  if not ros.handle:is_initialized() then
    ros.handle:source_ws()
  end

  pkg_path = util.strsplit(pkg_path, "/")
  local pkg_name, subdir_comps = pkg_path[1], { unpack(pkg_path, 2) }
  local subdir = table.concat(subdir_comps, "/")

  local pkg = ros.handle:get_pkg(pkg_name)
  if pkg == nil then
    vim.notify("Package " .. pkg_name .. "doesn't exist")
    return
  end
  local new_cwd = pkg.path .. "/" .. subdir
  vim.cmd.cd(new_cwd)
end

return ros
