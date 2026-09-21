#!/usr/bin/env bash
# Save the current occupancy grid. Keep the mapping process running.
set -e
PREFIX="${1:-map}"
rosrun map_server map_saver -f "$PREFIX"
echo "Saved ${PREFIX}.pgm and ${PREFIX}.yaml"
