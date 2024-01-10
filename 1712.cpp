#include <iostream>
using namespace std;

int main()
{
	int A, B, C, sum;

	cin >> A >> B >> C;

	if (B >= C) cout << "-1";
	
	else
	{
		sum = A / (C - B);
		cout << sum + 1;
	}

	return 0;
}