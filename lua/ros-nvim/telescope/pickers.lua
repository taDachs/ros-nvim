local pickers = require "telescope.pickers"
local finders = require "telescope.finders"
local conf = require("telescope.config").values

local ros = require("ros-nvim.ros")
local util = require("mutils")

local ros_pickers = {}

ros._telescope_result_list = nil

function build_result_list()
  if ros._telescope_result_list ~= nil then
    return ros._telescope_result_list
  end
  local results = {}
  for _, pkg in pairs(ros.get_package_list()) do
    for _, file in pairs(pkg.files) do
      local val = pkg.name .. " " .. util.relative_path(file, pkg.path)
      table.insert(results, {
        display = val,
        value = file,
        ordinal = val,
      })
    end
  end
  ros._telescope_result_list = results
  return results
end

function ros_pickers.ros_files(opts)
  if not ros.is_ros_sourced() then
    vim.notify("No ROS workspace sourced")
    return
  end
  opts = opts or { "list-names" }

  local finder = finders.new_table({
    results = build_result_list(),
    entry_maker = function(e) return e end,
  })

  pickers.new(opts, {
    prompt_title = "ros",
    finder = finder,
    sorter = conf.generic_sorter(opts),
    previewer = conf.file_previewer(opts)
  }):find()
end

return ros_pickers
