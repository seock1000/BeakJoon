#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void Recur(int n, char* pstr) {
	char str[200];

	strcpy(str, pstr);

	if (n == 0) {
		printf("%s\"����Լ��� ������?\"\n", str);
		printf("%s\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", str);
		return;
	}

	else {
		printf("%s\"����Լ��� ������?\"\n", str);
		printf("%s\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", str);
		printf("%s���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", str);
		printf("%s���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", str);
	}

	strcat(str, "____");
	Recur(n - 1, str);

	printf("%s��� �亯�Ͽ���.\n", str);
	
}

int main() {
	int n;
	char str[200] = "";
	scanf("%d", &n);

	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	Recur(n, str);
	printf("��� �亯�Ͽ���.\n");

	return 0;
}