local lazypath = vim.fn.stdpath "data" .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system {
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable", -- latest stable release
    lazypath,
  }
end

vim.opt.rtp:prepend(lazypath)
require("lazy").setup({
  {
    "nvim-telescope/telescope.nvim",
    dependencies = { "nvim-lua/plenary.nvim", },
    config = true,
    keys = {
      { "<leader>tr", "<cmd>Telescope ros ros<cr>", mode = "n", noremap = true },
    }
  },
  {
    "tadachs/ros-nvim",
    config = true,
    opts = {
      treesitter = {
        enabled = true,
      },
      commands = {
        enabled = true,
      },
      autocmds = {
        enabled = true,
      },
    },
    dependencies = { "nvim-lua/plenary.nvim" },
    dev = true,
    keys = {
      {
        "<leader>rol",
        function()
          require("ros-nvim.ros").open_launch_include()
        end,
        silent = true,
        noremap = true,
      },
      {
        "<leader>rd",
        function()
          require("ros-nvim.ros").show_interface_definition()
        end,
        silent = true,
        noremap = true,
      },
    },
    cmd = { "Rosed", "Rossource", "Roscd" }
  },
  {
    "nvim-treesitter/nvim-treesitter",
    run = ":TSUpdate",
    dependencies = {
      "nvim-treesitter/nvim-treesitter-textobjects",
      "nvim-telescope/telescope.nvim",
    },
    config = function()
      require("nvim-treesitter.configs").setup {
        -- ensure_installed = "ros",
        sync_install = false,
        highlight = {
          enable = true,
          additional_vim_regex_highlighting = true,
        },
      }
    end,
  },
}, {
  dev = {
    path = "~/dev",
  },
})

