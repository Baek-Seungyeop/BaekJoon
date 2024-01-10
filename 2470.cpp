#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); 
	ios_base::sync_with_stdio(0);

	int N, water, r, l, m = 2000000000, L = 0, R = 0;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> water;
		v.push_back(water);
	}
	sort(v.begin(), v.end());

	l = 0; r = N - 1;

	while (l < r) {
		if (v[l] + v[r] == 0) {
			cout << v[l] << " " << v[r];
			return 0;
		}
		if (abs(v[l] + v[r]) < m) {
			m = abs(v[l] + v[r]);
			L = l; R = r;
		}
		else if (v[l] + v[r] < 0) l++;
		else r--;
	}
	cout << v[L] << " " << v[R];

	return 0;
}