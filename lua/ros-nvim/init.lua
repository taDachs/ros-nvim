local config = require("ros-nvim.config")
local ros = require("ros-nvim.ros")

local treesitter = require("nvim-treesitter.parsers")

function get_parser_path()
  for _, p in pairs(vim.api.nvim_list_runtime_paths()) do
    if string.match(p, "ros%-nvim") then
      return p
    end
  end
end

if treesitter ~= nil then
  local parser_config = treesitter.get_parser_configs()
  parser_config.ros = {
    install_info = {
      url = get_parser_path() .. "/treesitter-ros/", -- local path or git repo
      files = {"src/parser.c"},
      -- optional entries:
      generate_requires_npm = false, -- if stand-alone parser without npm dependencies
      requires_generate_from_grammar = false, -- if folder contains pre-generated src/parser.c
    },
    filetype = "ros", -- if filetype does not match the parser name
  }
end

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


local ros_autocmd_grp = vim.api.nvim_create_augroup("ros-nvim", { clear = true })

vim.api.nvim_create_autocmd({"BufRead", "BufNewFile"}, {
  pattern = {"*.launch"},
  command = "setf xml",
  group = ros_autocmd_grp,
})

vim.api.nvim_create_autocmd({"BufRead", "BufNewFile"}, {
  pattern = {"*.msg"},
  command = "setf ros",
  group = ros_autocmd_grp,
})

vim.api.nvim_create_autocmd({"BufRead", "BufNewFile"}, {
  pattern = {"*.srv"},
  command = "setf ros",
  group = ros_autocmd_grp,
})

vim.api.nvim_create_autocmd({"BufRead", "BufNewFile"}, {
  pattern = {"*.action"},
  command = "setf ros",
  group = ros_autocmd_grp,
})

return M
