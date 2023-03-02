local pickers = require("telescope.pickers")
local finders = require("telescope.finders")
local conf = require("telescope.config").values

local ros = require("ros-nvim.ros")
local ros_config = require("ros-nvim.config")

local ros_pickers = {}

-- both must me absolute
local function relative_path(path, parent)
  local path_split = vim.fn.split(path, "/")
  local parent_split = vim.fn.split(parent, "/")
  local len_parent = 0
  for i, _ in ipairs(parent_split) do
    len_parent = i
  end
  local relative_split = { unpack(path_split, len_parent + 1) }
  return table.concat(relative_split, "/")
end

local function build_result_list()
  local results = {}
  for _, pkg_name in pairs(ros.handle:list_ws_scope_pkg_names(ros_config.telescope.ws_filter)) do
    local pkg = ros.handle:get_pkg(pkg_name)
    for _, file in pairs(pkg.files) do
      local val = pkg.name .. " " .. relative_path(file, pkg.path)
      table.insert(results, {
        display = val,
        value = file,
        ordinal = val,
      })
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
