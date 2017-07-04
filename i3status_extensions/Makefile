all: i3status_extensions

i3status_extensions: i3status_extensions.c
	gcc -Wall -O3 i3status_extensions.c -o i3status_extensions

clean:
	rm -f i3status_extensions
	sudo rm -f /usr/local/bin/i3status_extensions

deploy:
	sudo mv i3status_extensions /usr/local/bin/
