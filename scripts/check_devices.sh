#!/usr/bin/env bash
# Lightweight hardware sanity check reconstructed from lab troubleshooting notes.

set +e

echo "== USB serial devices =="
ls -l /dev/ttyUSB* 2>/dev/null || echo "No /dev/ttyUSB* devices found"

echo
echo "== Expected aliases used during the lab =="
ls -l /dev/rplidar 2>/dev/null || echo "/dev/rplidar not found"
ls -l /dev/ftdi 2>/dev/null || echo "/dev/ftdi not found"

echo
echo "== Joystick =="
ls -l /dev/input/js0 2>/dev/null || echo "/dev/input/js0 not found"

echo
echo "== USB device list =="
lsusb
