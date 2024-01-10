#include <iostream>
using namespace std;

unsigned long long koong[68];

void set_koong()
{
	koong[0] = 1;
	koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;

	for (int i = 4; i <= 67; i++)
	{
		koong[i] = koong[i - 4] + koong[i - 3] + koong[i - 2] + koong[i - 1];
	}
}

long long get_koong(int n)
{
	return koong[n];
}

int main()
{
	set_koong();

	int test, n;

	cin >> test;

	for (int i = 0; i < test; i++)
	{
		cin >> n;
		cout << get_koong(n) << endl;
	}

	return 0;
}