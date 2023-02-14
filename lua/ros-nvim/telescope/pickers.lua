local pickers = require("telescope.pickers")
local finders = require("telescope.finders")
local conf = require("telescope.config").values

local ros = require("ros-nvim.ros")
local ros_config = require("ros-nvim.config")
local util = require("mutils")

local ros_pickers = {}

local function build_result_list()
  local results = {}
  for _, pkg_name in pairs(ros.handle:list_pkg_names()) do
    local pkg = ros.handle:get_pkg(pkg_name)
    if ros.ws_type_includes(ros_config.telescope.ws_filter, pkg.ws_type) then
      for _, file in pairs(pkg.files) do
        local val = pkg.name .. " " .. util.relative_path(file, pkg.path)
        table.insert(results, {
          display = val,
          value = file,
          ordinal = val,
        })
      end
    end
  end
  return results
end

function ros_pickers.ros_files(opts)
  if not ros.handle:is_initialized() then
    ros.handle:source_ws()
  end
  opts = opts or { "list-names" }

  local finder = finders.new_table({
    results = build_result_list(),
    entry_maker = function(e)
      return e
    end,
  })

  pickers
    .new(opts, {
      prompt_title = "ros",
      finder = finder,
      sorter = conf.generic_sorter(opts),
      previewer = conf.file_previewer(opts),
    })
    :find()
end

return ros_pickers
