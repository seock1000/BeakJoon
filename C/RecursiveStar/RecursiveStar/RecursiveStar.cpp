#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void WriteStar(int x, int y, int n) {
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1) {
		printf(" ");
	}
	else {
		if (n / 3 == 0) {
			printf("*");
		}
		else {
			WriteStar(x, y, n / 3);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			WriteStar(i, j, n);
		}
		printf("\n");
	}

	return 0;
}