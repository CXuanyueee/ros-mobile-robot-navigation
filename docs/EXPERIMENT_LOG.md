# Experiment Log

This document reconstructs the main ROS practice milestones that were actually completed during the course.

## 1. ROS Environment & Workspace

Environment used:

- Ubuntu 16.04
- ROS Kinetic
- user: `robot`
- catkin workspace: `~/catkin_ws`
- robot workspace: `~/wpb_ws`

Core setup commands used in the course environment:

```bash
source /opt/ros/kinetic/setup.bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin_make
source devel/setup.bash
rospack profile
```

## 2. ROS Topic Communication

Completed basic ROS publisher/subscriber practice in C++:

```text
portfolio_talker  --(std_msgs/String: chatter)-->  portfolio_listener
```

Key concepts practiced:

- ROS node initialization
- `ros::NodeHandle`
- publisher / subscriber
- topic and message type
- callback functions
- `ros::spin()` / `ros::spinOnce()`
- catkin compilation

## 3. Mobile Robot Motion & Sensor Access

Worked with a real mobile robot platform and RPLIDAR-based perception.

During previous troubleshooting, the environment used device mappings consistent with:

```text
CP2102 serial device  -> /dev/ttyUSB0 -> /dev/rplidar
FTDI serial device    -> /dev/ttyUSB1 -> /dev/ftdi
Joystick              -> /dev/input/js0
```

These mappings are recorded from prior lab troubleshooting notes; exact udev-rule files are not preserved.

## 4. SLAM Mapping

### Simulation

```bash
source ~/wpb_ws/devel/setup.bash
roslaunch wpr_simulation wpb_robocup.launch
rosrun key_teleop key_teleop.py key_vel:=cmd_vel
roslaunch wpr_simulation wpb_gmapping.launch
```

The robot was manually driven through the environment while Gmapping accumulated laser scan information into a 2D occupancy-grid map.

### Real Robot

```bash
source ~/wpb_ws/devel/setup.bash
roslaunch wpb_home_tutorials gmapping.launch
```

A real-site map was successfully built during the lab.

## 5. Saving the Map

While the mapping process was still running:

```bash
rosrun map_server map_saver -f map
```

Output:

```text
map.pgm
map.yaml
```

These files were then used by the navigation stack.

## 6. AMCL Localization & Navigation

### Simulation

```bash
source ~/wpb_ws/devel/setup.bash
roslaunch wpr_simulation wpb_navigation.launch
```

### Real Robot

```bash
source ~/wpb_ws/devel/setup.bash
roslaunch wpb_home_tutorials nav.launch
```

RViz workflow:

1. Load saved occupancy map;
2. Use **2D Pose Estimate** to set/correct the initial pose;
3. Compare laser scan points with obstacle contours on the map;
4. Use **2D Nav Goal** to select a destination and heading;
5. Observe global path generation and robot execution;
6. Complete real-robot navigation acceptance.

## 7. Programmatic Navigation Goal

The course also introduced sending navigation goals through `move_base` + `actionlib`.

The reconstructed example is available at:

```text
src/simple_goal.cpp
```

It sends a simple forward goal in the `base_footprint` coordinate frame and waits for the navigation result.

## What I Learned

- ROS package/workspace structure
- topic-based communication
- relationship among laser sensing, mapping, localization and navigation
- occupancy-grid maps
- AMCL localization
- global/local planning concepts
- RViz-based robot pose correction and goal setting
- hardware troubleshooting in a real robot system
