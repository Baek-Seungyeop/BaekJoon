#include <iostream>
#include <vector>
using namespace std;

vector<int> network[101];
int visited[101];
int infectedPC = 0;

void speardVirus(int here) {
	visited[here] = 1;

	for (int i : network[here]) {
		if (!visited[i]) {
			speardVirus(i);
			infectedPC++;
		}
	}
}

int main() {
	int computer, link, a, b;
	cin >> computer >> link;

	for (int i = 0; i < link; i++) {
		cin >> a >> b;
		network[a].push_back(b);
		network[b].push_back(a);
	}

	speardVirus(1);
	cout << infectedPC;
	
	return 0;
}