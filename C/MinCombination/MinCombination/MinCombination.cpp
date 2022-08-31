#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int NumOfSugar(int sugar) {
	int three, five;

	five = sugar / 5;
	three = 0;

	while (five > 0) {
		if ((sugar - (five * 5)) % 3 == 0) {
			three = (sugar - (five * 5)) / 3;
			return five + three;
		}
		five--;
	}
	if (sugar % 3 == 0)
		return sugar / 3;

	return -1;
}

int main() {
	
	int sugar;

	scanf("%d", &sugar);
	printf("%d", NumOfSugar(sugar));

	return 0;
}