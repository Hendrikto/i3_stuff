backlight_dir = "/sys/class/backlight/intel_backlight/"
backlight_rule = $(shell whoami) ALL=NOPASSWD: /usr/bin/tee $(backlight_dir)brightness

all: backlight_ctl

backlight_ctl: backlight_ctl.sh
	echo $(backlight_rule) | sudo tee /etc/sudoers.d/backlight
	sudo ln -rs backlight_ctl.sh /usr/local/bin/backlight_ctl

clean:
	sudo rm /etc/sudoers.d/backlight
	sudo rm /usr/local/bin/backlight_ctl
