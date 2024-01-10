#include<stdio.h>
#include <algorithm>
#include <functional>
#pragma warning(disable:4996)

int toBinary(char binary[])
{
	int len = strlen(binary);
	int sum = 0;

	for (int i = 0; i < len; i++)
	{
		sum += (binary[i] - '0') * pow(2, len - i - 1);
	}
	return sum;
}

int main()
{
	int testcase;
	char binary[9];

	printf("테스트케이스를 입력해주세요.: ");
	scanf("%d", &testcase);
	
	for (int i = 0; i < testcase; i++)
	{
		printf("이진수 숫자를 입력해주세요.: ");
		scanf("%s", binary);

		printf("%d\n", toBinary(binary));
	}
}