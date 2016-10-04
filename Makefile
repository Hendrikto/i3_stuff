all: i3status_extensions

i3status_extensions: i3status_extensions/i3status_extensions.c
	g++ -Wall -O3 i3status_extensions/i3status_extensions.c -o i3status_extensions/i3status_extensions

clean:
	rm i3status_extensions/i3status_extensions
