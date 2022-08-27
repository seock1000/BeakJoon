#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ChooseRoom(int height, int width, int n) {
	int h, w;

	if (n % height == 0) {
		h = height;
		w = n / height;
	}
	else {
		h = (n % height);
		w = (n / height) + 1;
	}

	return h * 100 + w;
}

int main() {
	int arr[100][3], n;
	int i, t;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

	for (i = 0; i < t; i++)
		printf("%d\n", ChooseRoom(arr[i][0], arr[i][1], arr[i][2]));

	return 0;
}