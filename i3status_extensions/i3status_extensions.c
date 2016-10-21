#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BACKLIGHT_DIR "/sys/class/backlight/intel_backlight/"
#define MAX_BRIGHTNESS BACKLIGHT_DIR "max_brightness"
#define ACTUAL_BRIGHTNESS BACKLIGHT_DIR "actual_brightness"

/**
 * A tool to prepend the output of i3status with additional information.
 *
 * It currently adds a backlight brightness indicator.
 *
 * @author: Hendrik Werner
 */

int get_max_brightness() {
	int max_brightness_value;
	FILE* max_brightness = fopen(MAX_BRIGHTNESS, "r");
	fscanf(max_brightness, "%d", &max_brightness_value);
	fclose(max_brightness);
	return max_brightness_value;
}

int main() {
	int brightness = 0;
	int max_brightness = get_max_brightness();
	char* input = malloc(1);
	size_t size = 0;
	FILE* actual_brightness = fopen(ACTUAL_BRIGHTNESS, "r");
	while (true) {
		getline(&input, &size, stdin);
		fscanf(actual_brightness, "%d", &brightness);
		rewind(actual_brightness);
		printf("💡 %.0f%% | %s", brightness * 100 / (float) max_brightness, input);
		fflush(stdout);
	}
	fclose(actual_brightness);
	return EXIT_SUCCESS;
}
