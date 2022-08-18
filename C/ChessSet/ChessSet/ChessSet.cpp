#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int chessSet[6] = { 1, 1, 2, 2, 2, 8 };
	int yourSet[6];
	scanf("%d %d %d %d %d %d", &yourSet[0], &yourSet[1], &yourSet[2], &yourSet[3], &yourSet[4], &yourSet[5]);

	for (int i = 0; i < 6; i++)
		printf("%d ", chessSet[i] - yourSet[i]);

	return 0;
}