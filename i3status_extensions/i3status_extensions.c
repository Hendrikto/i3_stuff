#include <stdio.h>
#include <stdlib.h>

#define BACKLIGHT_DIR "/sys/class/backlight/intel_backlight/"

/**
 * A tool to prepend the output of i3status with additional information.
 *
 * It currently adds a backlight brightness indicator.
 *
 * @author: Hendrik Werner
 */

int get_max_brightness() {
	int max_brightness_value = 0;
	FILE* max_brightness = fopen(BACKLIGHT_DIR "max_brightness", "r");
	fscanf(max_brightness, "%d", &max_brightness_value);
	fclose(max_brightness);
	return max_brightness_value;
}

int main() {
	const int max_brightness = get_max_brightness();
	int brightness = 0;
	char* input = NULL;
	size_t size = 0;
	FILE* actual_brightness = fopen(BACKLIGHT_DIR "actual_brightness", "r");
	setbuf(actual_brightness, NULL);
	for (;;) {
		getline(&input, &size, stdin);
		fscanf(actual_brightness, "%d", &brightness);
		rewind(actual_brightness);
		printf("💡 %d%% | %s", brightness * 100 / max_brightness, input);
		fflush(stdout);
	}
	fclose(actual_brightness);
	free(input);
	return EXIT_SUCCESS;
}
