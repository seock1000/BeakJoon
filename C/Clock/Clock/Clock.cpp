#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int hour, minute;
	scanf("%d %d", &hour, &minute);

	if (minute < 45) {
		minute += 15;
		if (hour == 0)
			hour = 23;
		else
			hour -= 1;
	}
	else
		minute -= 45;

	printf("%d %d", hour, minute);

	return 0;
}