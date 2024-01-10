#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K, m;

	cin >> N >> K;

	vector<int> a(N + 1);
	vector<int> s(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= K; i++)
	{
		s[1] += a[i];
	}

	m = s[1];

	for (int i = 2; i <= N - K + 1; i++) {
		s[i] = s[i - 1] + a[K + i - 1] - a[i - 1];
		m = max(m, s[i]);
	}
	
	cout << m;

	return 0;
}