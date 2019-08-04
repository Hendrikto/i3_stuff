CC = gcc
CFLAGS += -Wall -Wextra -O3 -march=native

backlight_dir = /sys/class/backlight/intel_backlight
max_brightness = $(shell cat $(backlight_dir)/max_brightness)

DEFINES += -D BACKLIGHT_DIR=\"$(backlight_dir)\"
DEFINES += -D MAX_BRIGHTNESS=$(max_brightness)

all: install

%: %.c
	$(CC) $(CFLAGS) $(DEFINES) $< -o $@

clean:
	rm -f i3status_extensions

install: i3status_extensions
	sudo mv $< /usr/local/bin/

uninstall:
	sudo rm -f /usr/local/bin/i3status_extensions
