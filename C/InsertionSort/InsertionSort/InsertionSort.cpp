#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int arr[], int n) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int n, i;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	InsertionSort(arr, n);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}