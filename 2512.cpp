#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, M;
long long sum = 0;

long long check(vector<long long> &b) {
	long long left, right, mid, bsum, rst = 0;
	left = 0; right = b[N - 1];

	while (left <= right) {
		bsum = 0;
		mid = (right + left) / 2;
		for (long long i : b) {
			if (i - mid > 0) bsum += mid;
			else bsum += i;
		}
		if (bsum > M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			rst = max(rst, mid);
		}
	}
	return rst;
}

int main() {
	cin.tie(0); cout.tie(0); 
	ios_base::sync_with_stdio(0);

	cin >> N;
	vector<long long> budget(N);

	for (int i = 0; i < N; i++) {
		cin >> budget[i];
	}
	cin >> M;

	sort(budget.begin(), budget.end());
	for (long long i : budget)sum += i;
	if (sum <= M) cout << budget[N - 1];
	else {
		long long rst = check(budget);
		cout << rst;
	}

	return 0;
}