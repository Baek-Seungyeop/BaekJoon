#include <iostream>
using namespace std;

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void showStick(int stick[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << stick[i] << " ";
	}
	cout << endl;
}

bool checkStick(int stick[])
{
	for (int i = 1; i <= 5; i++)
	{
		if (i != stick[i - 1]) return false;
	}
	return true;
}

int main()
{
	int stick[5], i = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> stick[i];
	}

	while (1)
	{
		if (stick[i] > stick[i + 1])
		{
			swap(&stick[i], &stick[i + 1]);
			showStick(stick);
			if (checkStick(stick))break;
		}
		i++;
		if (i == 4)i = 0;
	}

	return 0;
}