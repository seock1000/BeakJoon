#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int MovingSnale(int a, int b, int v) {
	
	if ((v - a) % (a - b) != 0)
		return (v - a) / (a - b) + 2;
	else
		return (v - a) / (a - b) + 1;
}

int main() {
	int a, b, v;
	scanf("%d %d %d", &a, &b, &v);
	printf("%d", MovingSnale(a, b, v));

	return 0;
}