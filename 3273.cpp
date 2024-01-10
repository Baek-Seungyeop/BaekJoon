#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int x, n, cnt = 0;
vector<int> v;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int a, r, l;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	cin >> x;

	l = 0, r = n - 1;

	while (l < r) {
		if (v[l] + v[r] == x) {
			cnt++;
			l++;
		}
		else if (v[l] + v[r] > x) r--;
		else l++;
	}

	cout << cnt;
	return 0;
}