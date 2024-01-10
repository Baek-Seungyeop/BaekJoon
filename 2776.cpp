#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> note1;

bool findNum(int num, int left, int right) {
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (note1[mid] == num)return true;
		else if (note1[mid] > num) right = mid - 1;
		else left = mid + 1;
	}
	return false;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int T, N, M, num;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> num;
			note1.push_back(num);
		}
		sort(note1.begin(), note1.end());

		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> num;
			if (findNum(num, 0, N-1)) cout << "1\n";
			else cout << "0\n";
		}

		note1.clear();
	}
	return 0;
}