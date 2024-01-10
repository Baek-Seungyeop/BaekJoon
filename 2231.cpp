#include <iostream>
using namespace std;

int getNum(int n)
{
	int sum = n;
	int tmp;

	while (n > 0)
	{
		tmp = n % 10;
		sum += tmp;
		n /= 10;
	}

	return sum;
}

int main()
{
	int N;

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		if (N == getNum(i)) 
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}