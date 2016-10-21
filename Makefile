all: i3status_extensions

i3status_extensions: i3status_extensions/i3status_extensions.c
	gcc -Wall -O3 i3status_extensions/i3status_extensions.c -o i3status_extensions/i3status_extensions

clean:
	rm i3status_extensions/i3status_extensions
