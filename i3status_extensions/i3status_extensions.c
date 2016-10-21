#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * A tool to prepend the output of i3status with additional information.
 *
 * It currently adds a backlight brightness indicator.
 *
 * @author: Hendrik Werner
 */

int get_max_brightness() {
	int max_brightness_value;
	FILE* max_brightness = fopen("/sys/class/backlight/intel_backlight/max_brightness", "r");
	fscanf(max_brightness, "%d", &max_brightness_value);
	fclose(max_brightness);
	return max_brightness_value;
}

int main() {
	int brightness = 0;
	int max_brightness = get_max_brightness();
	char* input = malloc(1);
	size_t size = 0;
	FILE* actual_brightness = fopen("/sys/class/backlight/intel_backlight/actual_brightness", "r");
	while (true) {
		fscanf(actual_brightness, "%d", &brightness);
		rewind(actual_brightness);
		getline(&input, &size, stdin);
		printf("💡 %.0f%% | %s", brightness * 100 / (float) max_brightness, input);
		fflush(stdout);
	}
	fclose(actual_brightness);
	return EXIT_SUCCESS;
}
