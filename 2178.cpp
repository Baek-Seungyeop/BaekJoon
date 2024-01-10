#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int adj[100][100];
int visited[100][100];
int N, M, dst;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push(make_pair(y, x));

	while (q.size()) {
		pair<int, int> p = q.front(); q.pop();
		int py = p.first; int px = p.second;

		if (py == N - 1 && px == M - 1) {
			dst = visited[py][px];
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = py + dy[i];
			int nx = px + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || adj[ny][nx] == 0)continue;
			if (!visited[ny][nx]) {
				q.push({ ny, nx });
				visited[ny][nx] = visited[py][px] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	string num;

	for (int i = 0; i < N; i++)	{
		cin >> num;
		for (int j = 0; j < M; j++) {
			adj[i][j] = (int)(num[j]-'0');
		}
	}
	bfs(0, 0);

	cout << dst;
	return 0;
}