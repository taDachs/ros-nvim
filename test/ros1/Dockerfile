# Set the base image to ROS Noetic
FROM ros:noetic

# File Author / Maintainer
MAINTAINER Max Schik <max.schik@googlemail.com>

RUN apt-get update && apt-get install -y git

# Install dependencies for building ROS packages
RUN apt-get update && apt-get install -y \
    python3-rosdep \
    python3-rosinstall \
    python3-vcstools \
    python3-catkin-tools \
    wget

# Create workspace
RUN mkdir -p /root/workspace/src
WORKDIR /root/workspace/src

# Clone pr2_robot repo
RUN git clone https://github.com/PR2/pr2_robot.git src/pr2_robot

# Install any needed dependencies
WORKDIR /root/workspace
RUN rosdep update
RUN rosdep install --from-paths src --ignore-src --rosdistro noetic -y

# Build the workspace
RUN /bin/bash -c '. /opt/ros/noetic/setup.bash; cd /root/workspace; catkin build'

RUN mkdir -p /root/.config/nvim
RUN mkdir -p /root/dev/ros-nvim
COPY test/init.lua /root/.config/nvim/
COPY lua /root/dev/ros-nvim/lua
COPY ftplugin /root/dev/ros-nvim/ftplugin
COPY queries /root/dev/ros-nvim/queries
COPY treesitter-ros /root/dev/ros-nvim/treesitter-ros

WORKDIR /root

RUN wget https://github.com/neovim/neovim/releases/download/stable/nvim-linux64.tar.gz
RUN tar xvf ./nvim-linux64.tar.gz
RUN cp ./nvim-linux64/bin/nvim /bin/nvim
RUN cp -r ./nvim-linux64/lib/* /lib
RUN cp -r ./nvim-linux64/share/* /usr/share
