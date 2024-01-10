#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, rst = 1;
	int cnt[1001] = {0, };

	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && c < cnt[j]) c = cnt[j];
		}
		cnt[i] = c + 1;
		rst = max(rst, cnt[i]);
	}
	
	cout << rst;
	return 0;
}
