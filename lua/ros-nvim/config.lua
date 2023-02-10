local config = {
  only_workspace = true,
}

function config.update(opts)
  opts = opts or {}
  if opts.only_workspace ~= nil then
    config.only_workspace = opts.only_workspace
  end
  return config
end

return config
