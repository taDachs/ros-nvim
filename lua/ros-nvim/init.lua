local config = require("ros-nvim.config")
local ros = require("ros-nvim.ros")
M = {}

function M.setup(opts)
  M.config = config.update(opts)
end

vim.api.nvim_create_user_command("Rosed", function(opts)
                                            if #opts.fargs ~= 2 then
                                              vim.notify("Error, Rosed need exactly two arguments")
                                              return
                                            end
                                            ros.rosed(opts.fargs[1], opts.fargs[2])
                                          end,
                                          {
                                            nargs = "+",
                                            complete = ros.package_file_completion,
                                          }
                                )


return M
