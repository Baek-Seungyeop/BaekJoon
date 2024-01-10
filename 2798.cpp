#include <iostream>
using namespace std;

int main()
{
	int n, m, num[100], blackjack, min= 300000;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				blackjack = m - (num[i] + num[j] + num[k]);
				if (blackjack >= 0 && min > blackjack)min = blackjack;
			}
		}
	}
	blackjack = m - min;
	cout << blackjack;

	return 0;
}