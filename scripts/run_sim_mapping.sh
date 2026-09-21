#!/usr/bin/env bash
# Commands used for the simulation mapping workflow.
set -e
source ~/wpb_ws/devel/setup.bash

echo "Terminal 1: roslaunch wpr_simulation wpb_robocup.launch"
echo "Terminal 2: rosrun key_teleop key_teleop.py key_vel:=cmd_vel"
echo "Terminal 3: roslaunch wpr_simulation wpb_gmapping.launch"
