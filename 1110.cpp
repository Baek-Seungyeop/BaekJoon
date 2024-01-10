#include <iostream>
using namespace std;

int Plus(int num)
{
	int left, right;

	if (num < 10)
	{
		return 11 * num;
	}
	else
	{
		left = num % 10;
		right = (num / 10 + left) % 10;
		return left * 10 + right;
	}
}

int main()
{
	int N, cycle, cnt = 0;

	cin >> N;

	cycle = N;

	while (1)
	{
		N = Plus(N);
		cnt++;
		if (cycle == N) break;
	}

	cout << cnt;

	return 0;
}