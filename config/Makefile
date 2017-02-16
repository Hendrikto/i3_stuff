all: i3 i3status

i3: config
	ln -rs config ~/.config/i3/config

i3status: i3status.conf
	sudo ln -rs i3status.conf /etc/i3status.conf

clean:
	rm ~/.config/i3/config
	sudo rm /etc/i3status.conf
