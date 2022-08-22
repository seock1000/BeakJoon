#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int FindConstructure(int n) {
	int segSum, i;

	for (i = 0; i < n; i++) {
		int tmp = i;
		segSum = 0;
		do {
			segSum += tmp % 10;
			tmp /= 10;

		} while (tmp != 0);

		if (segSum + i == n)
			return i;
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", FindConstructure(n));

	return 0;
}
