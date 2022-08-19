#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int sum;
	int x;

	scanf("%d", &x);
	if (x % 2 == 0)
		sum = (1 + x) * (x / 2);
	else
		sum = (1 + x) * (x / 2) + ((x / 2) + 1);

	printf("%d", sum);

	return 0;
}