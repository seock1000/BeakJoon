#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _list {
	Node* head;
	Node* tail;
} List;

typedef List Queue;

void QueueInit(Queue* que) {
	que->head = NULL;
	que->tail = NULL;
};

int QIsEmpty(Queue* que) {
	if (que->head == NULL)
		return 1;
	else
		return 0;
}

void Enqueue(Queue* que, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (que->head == NULL) {
		newNode->next = NULL;
		newNode->prev = NULL;
		que->tail = newNode;
	}

	else {
		que->head->prev = newNode;
		newNode->next = que->head;
		newNode->prev = NULL;
	}
	que->head = newNode;
}

Data Dequeue(Queue* que) {
	Node* delNode = que->tail;
	Data rdata = delNode->data;

	que->tail = que->tail->prev;
	
	if (que->tail == NULL)
		que->head = NULL;
	else {
		que->tail->next = NULL;
	}

	free(delNode);

	return rdata;
}

void RadixSort(int arr[], int num, int maxLen) {
	Queue bucket[BUCKET_SIZE];
	int i, j, pos;
	int div = 1;
	int radix;

	for (i = 0; i < BUCKET_SIZE; i++) {
		QueueInit(&bucket[i]);
	}

	for (i = 0; i < maxLen; i++) {
		for (j = 0; j < num; j++) {
			radix = arr[j] / div % 10;
			Enqueue(&bucket[radix], arr[j]);
		}
		pos = 0;
		for (j = 0; j < BUCKET_SIZE; j++) {
			while (!QIsEmpty(&bucket[j])) {
				arr[pos] = Dequeue(&bucket[j]);
				pos++;
			}
		}
		div *= 10;
	}
}

int main() {
	int n, i;
	int cnt = 0;
	int tmp;
	int maxLen = 0;
	int* arr;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		tmp = arr[i];
		while (tmp != 0) {
			tmp /= 10;
			cnt++;
		}
		if (cnt > maxLen)
			maxLen = cnt;
		cnt = 0;
	}

	RadixSort(arr, n, maxLen);

	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	free(arr);
	return 0;
}