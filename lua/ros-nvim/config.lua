local util = require("mutils")

local config = {
  only_workspace = true,
  lazy_load_package_list = true,
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
