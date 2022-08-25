#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int BEPoint(int fixCost, int changeCost, int price) {
	int i = 1;

	if (changeCost >= price)
		return -1;

	return fixCost / (price - changeCost) + 1;

}

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	printf("%d", BEPoint(a, b, c));

	return 0;
}