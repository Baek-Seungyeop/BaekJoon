#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[20001];
int dist[20001] = { 0, };
bool visited[20001] = { false, };
const int INF = 987654321;
int V, E, K, u, v, w, rst;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// 오름차순 우선순위 큐

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> V >> E;
	cin >> K;
	fill(dist, dist + V + 1, INF);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w)); // end, cost
	}

	// 시작지점의 값을 0으로 놓는다
	pq.push(make_pair(0, K)); // dist, here
	dist[K] = 0;

	while (!pq.empty()) {
		// here : 현재 정점, here_dist : 가중치
		int here = pq.top().second; 
		int here_dist = pq.top().first;		pq.pop();

		// 최단 그래프에 포함되지 않으면 continue
		if (dist[here] != here_dist) continue; 
		
		// 현재 정점에서 갈 수 있는 간선들 확인
		for (pair<int, int> there : graph[here]) {
			// next : 해당 간선, next_dist : 해당 간선까지의 가중치
			int next = there.first;
			int next_dist = there.second;

			// dist는 최대값으로 설정되어 있기에 현재 위치까지의 값과 간선까지의 가중치를 update 한다
			if (dist[next] > dist[here] + next_dist) {
				dist[next] = dist[here] + next_dist;

				// 
				pq.push(make_pair(dist[next], next));
			}
		}

		// 간선들을 모두 탐색하면서 갱신하였기에 다음 반복에서의 pq의 가중치는 최소가 되는 가중치라고 볼 수 있다
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

    return 0;
}