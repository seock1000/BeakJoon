#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int HanNum(int n) {
	int cnt = n;

	while (n > 0) {
		int tmp = n;
		int minTmp;
		n--;

		minTmp = ((tmp % 100) / 10) - (tmp % 10);
		while (tmp) {
			tmp /= 10;
			if (tmp / 10 == 0)
				break;
			else if(minTmp != ((tmp % 100) / 10) - (tmp % 10))
				cnt--;
		}
	}

	return cnt;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", HanNum(n));
	return 0;
}