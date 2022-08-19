#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x, n, i;
	int price, quan;
	int sum = 0;

	scanf("%d", &x);
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d %d", &price, &quan);
		sum += price * quan;
	}

	if (sum == x)
		printf("Yes");
	else
		printf("No");

	return 0;
}