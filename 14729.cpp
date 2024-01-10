#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	float num, seven;
	cin >> N;
	priority_queue<float, vector<float>, greater<float>> score;

	for (int i = 0; i < N; i++) {
		cin >> num;
		score.push(num);
	}
	cout << fixed;
	cout.precision(3);
	
	for (int i = 0; i < 7; i++) {
		seven = score.top(); score.pop();
		cout << seven << '\n';
	}

	return 0;
}