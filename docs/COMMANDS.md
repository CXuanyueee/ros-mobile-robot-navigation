# Command Cheat Sheet

## ROS environment

```bash
source /opt/ros/kinetic/setup.bash
source ~/catkin_ws/devel/setup.bash
source ~/wpb_ws/devel/setup.bash
```

## Build a catkin workspace

```bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin_make
source devel/setup.bash
rospack profile
```

## Simulation mapping

```bash
roslaunch wpr_simulation wpb_robocup.launch
rosrun key_teleop key_teleop.py key_vel:=cmd_vel
roslaunch wpr_simulation wpb_gmapping.launch
```

## Real-robot mapping

```bash
roslaunch wpb_home_tutorials gmapping.launch
```

## Save map

```bash
rosrun map_server map_saver -f map
```

## Simulation navigation

```bash
roslaunch wpr_simulation wpb_navigation.launch
```

## Real-robot navigation

```bash
roslaunch wpb_home_tutorials nav.launch
```

## Create a navigation example package

```bash
cd ~/catkin_ws/src
catkin_create_pkg my_nav_package roscpp move_base_msgs actionlib
cd ~/catkin_ws
catkin_make
```

## Useful hardware checks

```bash
ls /dev/ttyUSB*
ls -l /dev/rplidar
ls -l /dev/ftdi
ls -l /dev/input/js0
lsusb
```
