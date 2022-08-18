#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int hour, minute;
	int ovenTime;

	scanf("%d %d", &hour, &minute);
	scanf("%d", &ovenTime);

	hour = hour + (ovenTime / 60);
	minute = minute + (ovenTime % 60);

	if (minute >= 60) {
		hour = hour + 1;
	}

	hour %= 24;
	minute %= 60;

	printf("%d %d", hour, minute);

	return 0;
}