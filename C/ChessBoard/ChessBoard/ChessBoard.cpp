#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define W 1
#define B 0

int ChessBoard(char board[][51], int n, int m) {
	int i, j;
	int x, y;
	int min = 64;
	char WB[9] = "WBWBWBWB";
	char BW[9] = "BWBWBWBW";

	for (i = 0; i <= n - 8; i++) {
		for (j = 0; j <= m - 8; j++) {
			int count = 0;
			x = y = 0;
			while (x < 8) {
				y = 0;
				while (y < 8) {
					if (board[i + x][j + y] != WB[y])
						count++;
					y++;
				}
				x++;
				y = 0;
				while (y < 8) {
					if (board[i + x][j + y] != BW[y])
						count++;
					y++;
				}
				x++;
			}

			if (count < min)
				min = count;

			count = 0;
			x = y = 0;
			while (x < 8) {
				y = 0;
				while (y < 8) {
					if (board[i + x][j + y] != BW[y])
						count++;
					y++;
				}
				x++;
				y = 0;
				while (y < 8) {
					if (board[i + x][j + y] != WB[y])
						count++;
					y++;
				}
				x++;
			}

			if (count < min)
				min = count;

		}
	}

	return min;
}

int main() {
	int n, m;
	char board[51][51];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &board[i]);

	printf("%d", ChessBoard(board, n, m));

	return 0;
}