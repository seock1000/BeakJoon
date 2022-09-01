#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>

typedef int Data;

typedef struct _heap {
	Data* arr;
	int cnt;
} Heap;

void HeapInit(Heap* heap, int n) {
	heap->arr = (Data*)malloc(sizeof(Data) * (n + 1));
	heap->cnt = 0;
}

void Push(Heap* heap, Data data) {
	heap->cnt++;
	int i = heap->cnt;

	while (i / 2 > 0) {
		if (heap->arr[i / 2] > data) {
			heap->arr[i] = heap->arr[i / 2];
			i /= 2;
		}
		else
			break;
	}
	heap->arr[i] = data;
	
}

Data Pop(Heap* heap) {
	int i = 1;
	int rData = heap->arr[1];
	int key = heap->arr[heap->cnt];
	heap->cnt--;

	while (i*2 <= heap->cnt) {
		int smallChild;

		if (i * 2 == heap->cnt)
			smallChild = i * 2;
		else {
			if (heap->arr[i * 2] < heap->arr[i * 2 + 1])
				smallChild = i * 2;
			else
				smallChild = i * 2 + 1;
		}

		if (heap->arr[smallChild] < key) {
			heap->arr[smallChild / 2] = heap->arr[smallChild];
			i = smallChild;
		}
		else
			break;
	}

	heap->arr[i] = key;

	if (heap->cnt == 0)
		free(heap->arr);

	return rData;
}

int IsHeapEmpty(Heap* heap) {
	if (heap->cnt == 0)
		return 1;
	else
		return 0;
}

int main() {
	int n, i;
	Data data;
	Heap heap;

	scanf("%d", &n);
	HeapInit(&heap, n);

	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		Push(&heap, data);
	}

	while (!IsHeapEmpty(&heap)) {
		printf("%d\n", Pop(&heap));
	}

	return 0;
}