local util = require("mutils")

local config = {
  lazy_load_package_list = true,
  telescope = {
    ws_filter = "current",
  },
  treesitter = {
    enabled = true,
  },
  commands = {
    enabled = true,
  },
  autocmds = {
    enabled = true,
  },
}

function config.update(opts)
  util.update_table(config, opts or {})
end

return config
