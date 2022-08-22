#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int FindName(int n) {
	int nameCnt;
	int cnt = 0;
	int i = 666;
	int tmp = 666;

	for (;;) {
		nameCnt = 0;
		tmp = i;
		while (tmp != 0) {			
			if (tmp % 10 == 6) {
				nameCnt++;
				if (nameCnt == 3) {
					cnt++;
					if (cnt == n)
						return i;
				}
			}
			else
				nameCnt = 0;
			tmp /= 10;
		}
		i++;
	}
	return 0;
}

int main() {
	int n;

	scanf("%d", &n);
	printf("%d", FindName(n));

	return 0;
}
