#!/usr/bin/env bash
# Real-robot mapping launch command from the course practice.
set -e
source ~/wpb_ws/devel/setup.bash
roslaunch wpb_home_tutorials gmapping.launch
