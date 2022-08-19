#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Star(int n) {
	if (n == 3) {
		printf("***************************\n");
		printf("* ** ** ** ** ** ** ** ** *\n");
		printf("***************************\n");
		return;
	}
	Star(n/3)
}

int main() {

}