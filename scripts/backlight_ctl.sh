#!/bin/bash

if [ $1 = "inc" ]; then
	xbacklight -inc 5
elif [ $1 = "dec" ]; then
	xbacklight -dec 5
fi

killall -USR1 i3status
