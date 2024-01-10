#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, T, * time, result;

	cin >> N;

	time = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> T;
		time[i] = T;
	}
	sort(time, time + N, greater<>());

	for (int i = 0; i < N; i++)
	{
		time[i] -= (N - i - 1);
	}

	sort(time, time + N);

	result = time[N - 1] + N + 1;
	cout << result;

	delete[] time;

	return 0;
}