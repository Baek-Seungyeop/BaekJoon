#include <iostream>
using namespace std;

long long dp[10001];

void setDP() {
	dp[0] = 1;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 10000; j++) {
			if (j - i >= 0)dp[j] += dp[j - i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	setDP();

	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}