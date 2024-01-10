#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, A[50], B[50], an, bn, sum = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> an;
		A[i] = an;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> bn;
		B[i] = bn;
	}
	sort(A, A + n);
	sort(B, B + n, greater<>());

	for (int i = 0; i < n; i++)
	{
		sum += A[i] * B[i];
	}
	cout << sum;

	return 0;
}