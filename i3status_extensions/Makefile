backlight_dir = "/sys/class/backlight/intel_backlight/"
max_brightness = $(shell cat $(backlight_dir)max_brightness)

all: i3status_extensions deploy

i3status_extensions: i3status_extensions.c
	gcc -Wall -Wextra -O3 -march=native $@.c -o $@\
		-D BACKLIGHT_DIR=\"$(backlight_dir)\"\
		-D MAX_BRIGHTNESS=$(max_brightness)

clean:
	rm -f i3status_extensions
	sudo rm -f /usr/local/bin/i3status_extensions

deploy:
	sudo mv i3status_extensions /usr/local/bin/
