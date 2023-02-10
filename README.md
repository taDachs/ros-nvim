# ros-nvim

Ros plugin for neovim

## Installation

### lazy.nvim

```lua
require("lazy").setup({
...
    {
        'tadachs/ros-nvim',
        config = function() require("ros-nvim").setup({only_workspace = true}) end,
        dependencies = { "tadachs/mutils.nvim" },
    },
...
})
```

## Features

- `Rosed` command with tab completion
- follow `$(find ...)` links in launch files
- telescope finder

## Example Setup

```lua
-- telescope finder
vim.keymap.set('n', '<leader>tr', '<cmd>Telescope ros ros<cr>', { noremap = true })

-- follow links in launch files
vim.keymap.set('x', '<leader>rol', function() require("ros-nvim.ros").open_launch_include() end, { silent = true, noremap = true })
vim.keymap.set('n', '<leader>rol', function() require("ros-nvim.ros").open_launch_include() end, { silent = true, noremap = true })
```
