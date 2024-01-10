#include <iostream>
using namespace std;

bool IsOdd(int n)
{
	if (n % 2 == 1) return true;
	return false;
}

int main()
{
	int n, fiveCent, twoCent, Coin;

	cin >> n;

	if (n == 1 || n == 3) cout << "-1";

	else
	{
		if (IsOdd(n % 5))
		{
			fiveCent = n / 5 - 1;

			n %= 5;
			n += 5;

			twoCent = n / 2;

			Coin = fiveCent + twoCent;
		}
		else
		{
			fiveCent = n / 5;

			n %= 5;

			twoCent = n / 2;

			Coin = fiveCent + twoCent;
		}
		cout << Coin;
	}
	return 0;
}