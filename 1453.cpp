#include <iostream>
using namespace std;

int main()
{
	int seat[101], n, number, cnt = 0;

	fill_n(seat, 101, 0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> number;

		if (seat[number] == 0)seat[number] = 1;
		else cnt++;
	}
	cout << cnt;

	return 0;
}