# i3_stuff
A repo with some i3 stuff.

## config
Configuration files for i3 and i3status.

## i3status_extensions
Prepend i3status with additional information.

Build:
```sh
make i3status_extensions
```

Deploy:
```sh
make deploy
```

Usage:
```sh
i3status | i3status_extensions
```
Not compatible with JSON output format. Use `output_format = "none"` in your `i3status.conf`.

## backlight_control
Control the backlight brightness.

I had some problems with `xbacklight`, so I wrote a replacement.

Build:
```sh
make backlight_control
```

Deploy:
```sh
make deploy
```

Usage:
```sh
$ backlight_control
Usage: backlight_control <mode> <value>
	mode: change | set

Examples:
	backlight_control change +10
	backlight_control change -10
	backlight_control set 50

```
