#!/bin/bash
backlight_dir=/sys/class/backlight/intel_backlight/
max_brightness=$(cat $backlight_dir"max_brightness")
brightness_step=$(bc <<< $max_brightness" / 20")

if [ $1 = "inc" ]; then
	new_brightness=$(bc -l <<< "$(cat $backlight_dir"brightness") + $brightness_step")
	echo $new_brightness > /sys/class/backlight/intel_backlight/brightness
elif [ $1 = "dec" ]; then
	new_brightness=$(bc -l <<< "$(cat $backlight_dir"brightness") - $brightness_step")
	echo $new_brightness > /sys/class/backlight/intel_backlight/brightness
fi

killall -USR1 i3status
