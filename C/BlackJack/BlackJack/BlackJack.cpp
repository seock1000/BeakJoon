#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int BlackJack(int n, int m) {
	int arr[101];
	int max = 0, sum;
	int i, j, t;

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n - 2; i++) {
		for (j = i + 1; j < n - 1; j++) {
			for (t = j + 1; t < n; t++) {
				sum = arr[i] + arr[j] + arr[t];
				if (sum == m)
					return sum;
				else if (sum < m && sum > max)
					max = sum;
			}
		}
	}

	return max;
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	printf("%d", BlackJack(n, m));

	return 0;
}
