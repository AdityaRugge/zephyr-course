# LED Sensor Application

This Zephyr application demonstrates a custom LED sensor driver with a shell
command interface for interactive control.

## Features
- `sensor fetch`: fetch a sensor sample and turn the LED on
- `sensor read`: read the sensor channel, turn the LED off, and print the returned value
- `sensor info`: print the LED sensor device name and ready state

## Build
From the workspace root:

```bash
cd /home/aditya/Workspace/zephyr-course
west build -b our_board app -p
```

## Flash

```bash
west flash
```

## Serial Console
Connect to the board serial console at 115200 baud:

```bash
screen /dev/ttyACM0 115200
```

or:

```bash
picocom -b 115200 /dev/ttyACM0
```

## Shell Usage
Once the board is running and the shell is ready, use:

```bash
sensor fetch
sensor read
sensor info
```

## Notes
- The shell assumes the LED sensor device is defined with devicetree label
  `led_sensor_0`.
- Ensure the custom sensor driver and shell support are enabled in `prj.conf` if necessary.
