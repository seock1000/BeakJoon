#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int HowManyPeople(int k, int n) {
	if (n == 1)
		return 1;

	int sum = 0;
	int tmp = HowManyPeople(k, n - 1);
	int* prevFloor = (int*)malloc(sizeof(int) * (n+1));
	int* curFloor = (int*)malloc(sizeof(int) * (n+1));

	for (int i = 0; i < k; i++) {
		if (i == 0) {
			for (int j = 0; j < n; j++)
				curFloor[j] = j + 1;
		}
		else {
			for (int j = 0; j < n; j++)
				prevFloor[j] = curFloor[j];
			for (int j = 0; j < n; j++) {
				sum = 0;
				for (int t = 0; t <= j; t++)
					sum += prevFloor[t];
				curFloor[j] = sum;
			}
		}
	}

	tmp += curFloor[n - 1];

	free(prevFloor);
	free(curFloor);

	return tmp;
}

int main() {
	int k, n, t;
	int i;

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", HowManyPeople(k, n));
	}

	return 0;
}