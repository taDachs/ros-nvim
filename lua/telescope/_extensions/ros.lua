local ros_pickers = require("ros-nvim.telescope.pickers")
-- print(ros_pickers.ros_files)

-- to execute the function
return require("telescope").register_extension({
  setup = function(ext_config, config)
    -- access extension config and user config
  end,
  exports = {
    ros = ros_pickers.ros_files,
  },
})
