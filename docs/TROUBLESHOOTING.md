# Troubleshooting Notes

> These notes are reconstructed from previous lab troubleshooting. Exact historical terminal logs were not preserved, so this document records the **problem categories and diagnostic logic** rather than claiming verbatim recovery of every command/output.

## 1. Serial device not found

Observed during real-robot connection and sensor bring-up.

Checks:

```bash
ls /dev/ttyUSB*
lsusb
```

Previously used device mapping:

```text
CP2102 -> /dev/ttyUSB0 -> /dev/rplidar
FTDI   -> /dev/ttyUSB1 -> /dev/ftdi
```

Things to verify:

- USB device is connected to the virtual machine / robot computer;
- serial device node exists;
- expected alias exists;
- current user has serial-port permission;
- another process is not occupying the device.

## 2. RPLIDAR bind / startup failure

Symptoms included failure to start the laser driver or missing laser data in RViz.

Diagnostic sequence:

1. Check whether the USB serial device appears;
2. Confirm `/dev/rplidar` exists;
3. Check USB/serial permission;
4. Restart the relevant launch process after reconnecting hardware;
5. Confirm scan data appears in RViz before starting mapping.

## 3. Joystick missing

A previous issue involved the joystick device not appearing as:

```text
/dev/input/js0
```

Reconnecting the device / USB passthrough was part of the practical troubleshooting process.

## 4. RViz / TF issues

During mapping and navigation, issues included RViz instability and TF extrapolation warnings.

General checks used in the lab workflow:

- make sure required launch files are still running;
- verify sensor and robot frames are available;
- avoid closing Gmapping before saving the map;
- restart RViz / launch stack if state becomes inconsistent.

## 5. Navigation: `Failed to get a plan`

Potential practical causes considered during the lab:

- initial pose in RViz is wrong;
- laser points do not align with the saved map;
- goal is placed in an occupied/inflated obstacle region;
- map / costmap state is inconsistent;
- robot localization has not converged.

A key practical check was to use **2D Pose Estimate** until the live laser scan approximately aligned with the static obstacle contours before sending a **2D Nav Goal**.

## 6. Power / hardware state

Real-robot behavior can also be affected by:

- emergency stop state;
- USB power state;
- insufficient robot battery level;
- loose sensor / controller connection.

These hardware checks were important because not every failure was caused by ROS software.
