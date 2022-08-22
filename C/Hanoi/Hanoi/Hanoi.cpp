#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count = 0;
int arr[1048575][2];

void HanoiMove(int n, int from, int by, int to) {

	if (n == 1) {
		arr[count][0] = from;
		arr[count][1] = to;
		count++;
		return;
	}

	else {
		HanoiMove(n - 1, from, to, by);
		arr[count][0] = from;
		arr[count][1] = to;
		count++;
		HanoiMove(n - 1, by, from, to);
	}
}

int main() {
	int n;

	scanf("%d", &n);

	HanoiMove(n, 1, 2, 3);

	printf("%d\n", count);

	for (int i = 0; i < count; i++)
		printf("%d %d\n", arr[i][0], arr[i][1]);
		
	return 0;
}