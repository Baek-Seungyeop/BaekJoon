#include <iostream>
using namespace std;

int main()
{
	int N, cnt = 1;

	cin >> N;

	while (1)
	{
		N -= cnt;
		if (N < 0)break;
		cnt++;
	}
	if (cnt % 2 == 1) cout << -N;
	else cout << 0;

	return 0;
}