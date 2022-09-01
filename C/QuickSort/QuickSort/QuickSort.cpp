#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Swap(int arr[], int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

void MoveMidValueToLeft(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	if (arr[left] < arr[right]) {
		if (arr[right] < arr[mid])
			Swap(arr, left, right);
		else if (arr[left] < arr[mid])
			Swap(arr, left, mid);
	}
	else {
		if (arr[right] > arr[mid])
			Swap(arr, left, right);
		else if (arr[left] > arr[mid])
			Swap(arr, left, mid);
	}
}

int Partition(int arr[], int left, int right) {
	MoveMidValueToLeft(arr, left, right);
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (arr[low] <= pivot && low <= right) {
			low++;
		}
		while (arr[high] >= pivot && high > left) {
			high--;
		}
		if (low <= high) {
			Swap(arr, low, high);
		}
	}

	Swap(arr, left, high);
	
	return high;
}

void QuickSort(int arr[], int left, int right) {
	if (left < right) {
		int pivot = Partition(arr, left, right);
	
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main() {
	int n, i;
	scanf("%d", &n);

	int* arr;
	arr = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	QuickSort(arr, 0, n - 1);

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	free(arr);
	return 0;
}