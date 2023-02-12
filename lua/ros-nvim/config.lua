local config = {
  only_workspace = true,
  lazy_load_package_list = true,
}

function config.update(opts)
  opts = opts or {}
  if opts.only_workspace ~= nil then
    config.only_workspace = opts.only_workspace
  end
  if opts.lazy_load_package_list ~= nil then
    config.lazy_load_package_list = opts.lazy_load_package_list
  end
  return config
end

return config
