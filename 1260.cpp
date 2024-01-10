#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int visited[1001];
vector<int> adj[1001];
int N, M, V, x, y;

void dfs(int v) {
	visited[v] = 1;
	cout << v << " ";

	for (int i : adj[v]) {
		if (!visited[i]) {	
			dfs(i);
		}
	}
	return;
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	
	while (q.size()) {
		int h = q.front(); q.pop();
		cout << h << " ";
		for (int i : adj[h]) {
			if (visited[i]) continue;
			q.push(i);
			visited[i] = 1;
		}
	}
}

int main() {
	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for (int i = 0; i < 1001; i++) {
		if (!adj[i].empty()) {
			sort(adj[i].begin(), adj[i].end());
		}
	}

	dfs(V);
	cout << '\n';
	fill(visited, visited + 1001, 0);
	bfs(V);

	return 0;
}