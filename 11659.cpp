#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M, x, y, num;

	cin >> N >> M;

	vector<int> a(N + 1);
	vector<int> s(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		cout << s[y] - s[x - 1] << "\n";
	}
	return 0;
}