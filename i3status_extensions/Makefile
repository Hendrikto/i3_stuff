CC = gcc
CFLAGS += -Wall -Wextra -O3 -march=native

backlight_dir = /sys/class/backlight/intel_backlight
max_brightness = $(shell cat $(backlight_dir)/max_brightness)

DEFINES += -D BACKLIGHT_DIR=\"$(backlight_dir)\"
DEFINES += -D MAX_BRIGHTNESS=$(max_brightness)

prefix = /usr/local

all: i3status_extensions

%: %.c
	$(CC) $(CFLAGS) $(DEFINES) $< -o $@

clean:
	rm -f i3status_extensions

install: i3status_extensions
	sudo mv $< $(DESTDIR)$(prefix)/bin/

uninstall:
	sudo rm -f $(DESTDIR)$(prefix)/bin/i3status_extensions
