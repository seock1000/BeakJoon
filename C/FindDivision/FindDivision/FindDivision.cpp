#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void PrintDiv(int n) {
	int cnt = 2;
	int tmp = n;

	if (n == 1) {
		printf("1/1");
		return;
	}

	tmp--;
	while (tmp > cnt) {
		tmp -= cnt;
		cnt++;
	}

	if (cnt % 2 == 0) {
		printf("%d/%d", tmp, cnt - tmp + 1);
	}
	else {
		printf("%d/%d", cnt - tmp + 1, tmp);
	}
}

int main() {
	int n;

	scanf("%d", &n);

	PrintDiv(n);
	return 0;
}