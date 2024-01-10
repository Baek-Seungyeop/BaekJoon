#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); 
	ios_base::sync_with_stdio(0);

	vector<pair<int, int>> v;
	int N, start, end, cnt = 1, tmp;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(), v.end());
	 
	tmp = v[0].first;
	for (int i = 1; i < N; i++) {
		if (v[i].second >= tmp) {
			cnt++;
			tmp = v[i].first;
		}
	}

	cout << cnt;

	return 0;
}