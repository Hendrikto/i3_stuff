#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>

#define EVENT_BUFFER_SIZE sizeof(struct inotify_event) + NAME_MAX + 1

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
	int inotify_fd = inotify_init1(IN_NONBLOCK);
	inotify_add_watch(inotify_fd, BACKLIGHT_DIR "actual_brightness", IN_MODIFY);
	char event_buffer[EVENT_BUFFER_SIZE];
	FILE* actual_brightness = fopen(BACKLIGHT_DIR "actual_brightness", "r");
	setbuf(actual_brightness, NULL);
	fscanf(actual_brightness, "%d", &brightness);
	rewind(actual_brightness);
	for (;;) {
		getline(&input, &size, stdin);
		if (read(inotify_fd, event_buffer, EVENT_BUFFER_SIZE) > 0) {
			fscanf(actual_brightness, "%d", &brightness);
			rewind(actual_brightness);
		}
		printf("💡 %d%% | %s", brightness * 100 / MAX_BRIGHTNESS, input);
		fflush(stdout);
	}
	fclose(actual_brightness);
	free(input);
	return EXIT_SUCCESS;
}
