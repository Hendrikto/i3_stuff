#include <stdio.h>
#include <stdlib.h>

/**
 * A tool to prepend the output of i3status with additional information.
 *
 * It currently adds a backlight brightness indicator.
 *
 * @author: Hendrik Werner
 */

int main() {
	int brightness = 0;
	char* input = NULL;
	size_t size = 0;
	FILE* actual_brightness = fopen(BACKLIGHT_DIR "/actual_brightness", "r");
	setbuf(actual_brightness, NULL);
	fscanf(actual_brightness, "%d", &brightness);
	rewind(actual_brightness);
	for (;;) {
		getline(&input, &size, stdin);
		fscanf(actual_brightness, "%d", &brightness);
		rewind(actual_brightness);
		printf("💡 %d%% | %s", brightness * 100 / MAX_BRIGHTNESS, input);
		fflush(stdout);
	}
	fclose(actual_brightness);
	free(input);
	return EXIT_SUCCESS;
}
