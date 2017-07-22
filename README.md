# i3_stuff
A repo with some i3 stuff.

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

I had some problems with `xbacklight` in combination with the proprietary nvidia driver, so I wrote a replacement.

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
Usage: backlight_control [+|-]<value>

Examples:
        backlight_control +10
        backlight_control -10
        backlight_control 50

```
