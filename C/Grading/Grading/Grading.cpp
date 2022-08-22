#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int size[50][2];
	int arr[50];
	int n , i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d %d", &size[i][0], &size[i][1]);

	for (i = 0; i < n; i++) {
		arr[i] = n;
		for (j = 0; j < n; j++) {
			if (i != j) {
				if (!(size[i][0] < size[j][0] && size[i][1] < size[j][1]))
					arr[i]--;
			}
		}
		printf("%d ", arr[i]);
	}	

	return 0;
}