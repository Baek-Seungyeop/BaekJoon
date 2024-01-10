#include<stdio.h>
#pragma warning(disable:4996)

void PrintStar(int size)
{
	int count = 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) printf(" ");

		}
	}
}

int main()
{
	int size;

	scanf("%d", &size);

	PrintStar(size);

	return 0;
}