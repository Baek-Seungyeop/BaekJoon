#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	int MAX = -1;
	int* gems = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> gems[i];
		if (gems[i] > MAX)MAX = gems[i];
	}

	int left = 1, right = MAX;
	int ans = 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		int sum = 0;
		for (int i = 0; i < M; i++) {
			sum += ceil((double)gems[i] / mid);
		}

		if (sum <= N) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans;
}