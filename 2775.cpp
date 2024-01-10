/*#include <iostream>
using namespace std;

int people[15][15];

void zeroFloor()
{
	for (int i = 0; i < 15; i++)
	{
		people[0][i] = i;
	}
}

int getFloor(int k, int n)
{
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			people[i][j] = people[i - 1][j] + people[i][j - 1];
		}
	}
	
	return people[k][n];
}

int main()
{
	int TC, k, n, result; // k : �� n : ȣ

	cin >> TC; 

	zeroFloor();

	while (TC--)
	{
		cin >> k >> n;

		result = getFloor(k, n);

		cout << result << endl;
	}

	return 0;
}*/
�׳� �Լ�

/*#include <iostream>

using namespace std;

int getNum(int a, int b) {
    if (b == 1)
        return 1;
    if (a == 0)
        return b;
    return (getNum(a - 1, b) + getNum(a, b - 1));
}

int main() {
    int T, k, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k >> n;
        cout << getNum(k, n) << '\n';
    }
}*/
����Լ�