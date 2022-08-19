#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b;
	int sum[100], x;
	
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		scanf("%d %d", &a, &b);
		sum[i] = a + b;
	}

	for (int i = 0; i < x; i++)
		printf("%d\n", sum[i]);

	return 0;
}