#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

/**
 * A tool to prepend the output of i3status with additional information.
 *
 * It currently adds a backlight brightness indicator.
 *
 * @author: Hendrik Werner
 */

int get_max_brightness() {
	std::ifstream max_brightness;
	max_brightness.open("/sys/class/backlight/intel_backlight/max_brightness");
	int max_brightness_value;
	max_brightness >> max_brightness_value;
	return max_brightness_value;
}

int main() {
	int brightness = 0;
	int max_brightness = get_max_brightness();
	char* input = (char*) malloc(1);
	size_t size = 0;
	std::ifstream actual_brightness;
	actual_brightness.open("/sys/class/backlight/intel_backlight/actual_brightness");
	while (true) {
		actual_brightness >> brightness;
		actual_brightness.seekg(0);
		getline(&input, &size, stdin);
		printf("⛭ %.0f%% | %s", brightness * 100 / (float) max_brightness, input);
		std::cout.flush();
	}
	return 0;
}
