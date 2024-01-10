#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int N, x, y, rst = 0;
	vector<pair<int, int>> line;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		line.push_back({ x, y });
	}
	
	sort(line.begin(), line.end());

	int tmpX = line[0].first, tmpY = line[0].second;

	for (int i = 1; i < N; i++) {
		if (line[i].first <= tmpY) {
			tmpY = max(tmpY, line[i].second);
		}
		else {
			rst += abs(tmpY - tmpX);
			tmpX = line[i].first; tmpY = line[i].second;
		}
	}
	rst += abs(tmpY - tmpX);

	cout << rst;

	return 0;
}