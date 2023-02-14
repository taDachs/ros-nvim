local util = require("mutils")
local ros = require("ros-nvim.ros")

local completion = {}

function completion.package_file_completion(arg_lead, cmd_line, cursor_pos)
  if not ros.handle:is_initialized() then
    ros.handle:source_ws()
  end

  cmd_line = string.sub(cmd_line, 1, string.len(cmd_line) - string.len(arg_lead))
  local args = util.strsplit(cmd_line)
  if #args == 1 then -- only command
    return ros.handle:list_pkg_names()
  elseif #args == 2 then -- command and first arg
    local pkg = ros.handle:get_pkg(args[2])

    if pkg ~= nil then
      return util.map(pkg.files, util.get_basename)
    else
      return {}
    end
  end
end

function completion.roscd_completion(arg_lead, cmd_line, cursor_pos)
  if not ros.handle:is_initialized() then
    ros.handle:source_ws()
  end

  local arg_lead_comps = util.strsplit(arg_lead, "/")
  if #arg_lead_comps <= 1 and not string.match(arg_lead, "/$") then
    return ros.handle:list_pkg_names()
  end

  local pkg = ros.handle:get_pkg(arg_lead_comps[1])
  if pkg == nil then
    return {}
  end

  local options = {}
  for _, dir in pairs(pkg.dirs) do
    dir = pkg.name .. string.sub(dir, string.len(pkg.path) + 1)
    -- length of current path without package
    if util.get_dirname(arg_lead) == util.get_dirname(dir) then
      table.insert(options, dir)
    end
  end

  print(vim.inspect(options))
  return options
end

return completion
