#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void SelfNum() {
	int n = 1;
	int cnt;
	int sum, tmp;

	while (n <= 10000) {
		cnt = 0;
		for (int i = 1; i < n; i++) {
			sum = i;
			tmp = i;
			while (tmp != 0) {
				sum += tmp % 10;
				tmp /= 10;
			}
			if (sum == n) {
				cnt = 1;
				break;
			}
		}
		if (!cnt)
			printf("%d\n", n);
		n++;
	}
}

int main() {
	SelfNum();
	
	return 0;
}