# i3_stuff
A repo with some i3 stuff.

## i3status_extensions
Prepend i3status with additional information.

### Build
```sh
make i3status_extensions
```

### Install
```sh
make install
```

### Uninstall
```sh
make uninstall
```

### Usage
```sh
i3status | i3status_extensions
```
Not compatible with JSON output format. Use `output_format = "none"` in your `i3status.conf`.
