#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int BeeHouseRoute(int n) {
	int tmp = 1;
	int cnt = 1;

	for (;;) {
		if (n <= tmp)
			return cnt;
		tmp += cnt * 6;
		cnt++;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", BeeHouseRoute(n));
	return 0;
}