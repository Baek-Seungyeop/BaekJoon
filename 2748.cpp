#include <iostream>
using namespace std;

long long dp[91];

long long fibo(int n) {
	dp[0] = 0;	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] += dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	cout << fibo(n);

	return 0;
}