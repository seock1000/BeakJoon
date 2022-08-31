#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
} Node;

typedef struct _stack {
	Node* top;
} Stack;

void StackInit(Stack* pstack) {
	pstack->top = NULL;
}

void Push(Stack* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->top;
	pstack->top = newNode;
}

Data Pop(Stack* pstack) {
	Node* rnode = pstack->top;
	Data rdata = pstack->top->data;

	pstack->top = rnode->next;
	free(rnode);

	return rdata;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->top == NULL)
		return TRUE;
	else
		return FALSE;
}

int main() {
	Stack a, b, sum;
	char data;

	StackInit(&a);
	StackInit(&b);

	for (;;) {
		scanf("%c", &data);
		if (data == ' ')
			break;
		Push(&a, data);
	}
	for (;;) {
		scanf("%c", &data);
		if (data == '\n')
			break;
		Push(&b, data);
	}

	StackInit(&sum);

	int plus = 0, exceed = 0;
	while (!SIsEmpty(&a) && !SIsEmpty(&b)) {
		plus = 0;
		plus = (Pop(&a) - '0') + (Pop(&b) - '0');
		if (exceed > 0) {
			plus += 1;
			exceed = 0;
		}

		if (plus >= 10) {
			plus %= 10;
			exceed = 1;
		}

		Push(&sum, plus);
	}

	while (!SIsEmpty(&a)) {
		plus = 0;
		plus = (Pop(&a) - '0');
		if (exceed > 0) {
			plus += 1;
			exceed = 0;
		}

		if (plus >= 10) {
			plus %= 10;
			exceed = 1;
		}
		Push(&sum, plus);
	}

	while (!SIsEmpty(&b)) {
		plus = 0;
		plus = (Pop(&b) - '0');
		if (exceed > 0) {
			plus += 1;
			exceed = 0;
		}

		if (plus >= 10) {
			plus %= 10;
			exceed = 1;
		}
		Push(&sum, plus);
	}

	if (exceed > 0) {
		Push(&sum, 1);
	}

	while (!SIsEmpty(&sum)) {
		printf("%d", Pop(&sum));
	}
}
