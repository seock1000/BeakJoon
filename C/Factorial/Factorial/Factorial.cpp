#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Factorial(int n) {
	if (n == 0)
		return 1;
	
	return Factorial(n - 1) * n;
}

int main() {
	int n;

	scanf("%d", &n);
	printf("%d", Factorial(n));

	return 0;
}