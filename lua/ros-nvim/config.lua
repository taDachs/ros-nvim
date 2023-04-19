local function update_table(a, b)
  for k, v in pairs(b) do
    if type(v) == "table" then
      if type(a[k] or false) == "table" then
        vim.tbl_extend("force", a[k] or {}, b[k] or {})
      else
        a[k] = v
      end
    else
      a[k] = v
    end
  end
  return a
end

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
  completion = {
    cmp = true,
  },
}

function config.update(opts)
  update_table(config, opts or {})
end

return config
