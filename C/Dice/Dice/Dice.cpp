#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;
	int cash;
	scanf("%d %d %d", &a, &b, &c);

	if (a == b) {
		if (b == c)
			cash = 10000 + a * 1000;
		else
			cash = 1000 + a * 100;
	}

	else if (a == c)
		cash = 1000 + a * 100;

	else if (b == c)
		cash = 1000 + b * 100;

	else {
		if (a > b) {
			if (a > c)
				cash = a * 100;
			else
				cash = c * 100;
		}
		else {
			if (b > c)
				cash = b * 100;
			else
				cash = c * 100;
		}
	}

	printf("%d", cash);

	return 0;
}