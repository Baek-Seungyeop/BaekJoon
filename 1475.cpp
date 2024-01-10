#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string num;
	int check[10] = { 0, }, cnt, iMin = 10, iMax = -1;
	cin >> num;

	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] >= '0' && num[i] <= '9')
		{
			int idx = (int)num[i] - 48;
			if (idx == 9)idx = 6;
			check[idx]++;
		}
	}
	if (check[6] % 2 == 1)
	{
		check[6] /= 2;
		check[6] += 1;
	}
	else
	{
		check[6] /= 2;
	}

	for (int i = 0; i < 9; i++)
	{
		if (check[i] != 0)
		{
			iMin = min(iMin, check[i]);
		}
	}
	cnt = iMin;

	for (int i = 0; i < 9; i++)
	{
		if (check[i] > 0)
		{
			check[i] -= iMin;
			iMax = max(iMax, check[i]);
		}
	}
	cnt += iMax;
	cout << cnt;

	return 0;
}