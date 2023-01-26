# Use the existing ROS-NOETIC image
FROM osrf/ros2:nightly-rmw-nonfree

LABEL maintainer="Kevin Vega <vegakevinrdz@gmail.com>"

# Install dependencies
RUN apt-get update -qq && \
    apt-get install -y \
    build-essential \
    nano \
    git \
    autoconf \
    libtool \
    python3-pip \
    mesa-utils \
    --no-install-recommends terminator \
    ros-humble-desktop-full 
    # rm -rf /var/lib/apt/lists/*

# Init catkin_home directoy
RUN mkdir /tam_ws
COPY tam_ws/ tam_ws/

# Change Workdir
WORKDIR /tam_ws

# catkin_make
RUN /bin/bash -c '. /opt/ros/humble/setup.bash;colcon build'

# Add ROS environment variables automatically
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
RUN echo "[ -f /tam_ws/install/setup.bash ] && source /tam_ws/install/setup.bash" >> ~/.bashrc
# RUN echo "export GAZEBO_MODEL_PATH=/tam_ws/src/simulation/models:$GAZEBO_MODEL_PATH" >> ~/.bashrc
# RUN echo "export GAZEBO_RESOURCE_PATH=/catkin_home/src/simulation:$GAZEBO_RESOURCE_PATH" >> ~/.bashrc


ENTRYPOINT [ "/bin/bash", "-l", "-c" ]