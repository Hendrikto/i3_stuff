# i3_stuff
A repo with some i3 stuff.

## i3status_extensions
Prepend i3status with additional information.

Build:
```sh
make i3status_extensions
```

Install:
```sh
make install
```

Usage:
```sh
i3status | i3status_extensions
```
Not compatible with JSON output format. Use `output_format = "none"` in your `i3status.conf`.

Uninstall:
```sh
make uninstall
```

## backlight_control
Control the backlight brightness.

I had some problems with `xbacklight` in combination with the proprietary nvidia driver, so I wrote a replacement.

Build:
```sh
make backlight_control
```

Install:
```sh
make install
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

`backlight_control +n` increases brightness by n%

`backlight_control -n` decreases brightness by n%

`backlight_control n` sets the brightness to n%

Uninstall:
```sh
make uninstall
```
