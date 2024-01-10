#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int nx, ny, N, M;
int wall = 3, maxSafeArea = 0;
int map[8][8], copyMap[8][8], visited[8][8];
vector<int> v, b;

int countSafeArea() {
	int safeArea = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copyMap[i][j] == 0)
				safeArea++;
		}
	}
	return safeArea;
}

void dfs(int y, int x) {
	visited[y][x] = 1;
	
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		if (copyMap[ny][nx] == 0 && !visited[ny][nx]) {
			copyMap[ny][nx] = 2;
			dfs(ny, nx);
		}
	}
	return;
}

void spreadVirus() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copyMap[i][j] == 2 && !visited[i][j])
				dfs(i, j);
		}
	}
}

void combiOfWall(int start, vector<int>b) {
	if (b.size() == wall) {
		copy(&map[0][0], &map[0][0] + 64, &copyMap[0][0]);
		fill(&visited[0][0], &visited[7][8], 0);

		for (int i : b) {
			int iy = i / M;
			int ix = i % M;
			copyMap[iy][ix] = 1;	
		}

		spreadVirus();
		maxSafeArea = max(maxSafeArea, countSafeArea());
		return;
	}
	for (int i = start + 1; i < v.size(); i++) {
		b.push_back(v[i]);
		combiOfWall(i, b);
		b.pop_back();
	}
	return;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0) v.push_back(i * M + j);
		}
	}

	combiOfWall(-1, b);	

	cout << maxSafeArea;

	return 0;
}