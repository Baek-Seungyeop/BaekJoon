#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[20001];
int dist[20001] = { 0, };
bool visited[20001] = { false, };
const int INF = 987654321;
int V, E, K, u, v, w, rst;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// �������� �켱���� ť

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

	// ���������� ���� 0���� ���´�
	pq.push(make_pair(0, K)); // dist, here
	dist[K] = 0;

	while (!pq.empty()) {
		// here : ���� ����, here_dist : ����ġ
		int here = pq.top().second; 
		int here_dist = pq.top().first;		pq.pop();

		// �ִ� �׷����� ���Ե��� ������ continue
		if (dist[here] != here_dist) continue; 
		
		// ���� �������� �� �� �ִ� ������ Ȯ��
		for (pair<int, int> there : graph[here]) {
			// next : �ش� ����, next_dist : �ش� ���������� ����ġ
			int next = there.first;
			int next_dist = there.second;

			// dist�� �ִ밪���� �����Ǿ� �ֱ⿡ ���� ��ġ������ ���� ���������� ����ġ�� update �Ѵ�
			if (dist[next] > dist[here] + next_dist) {
				dist[next] = dist[here] + next_dist;

				// 
				pq.push(make_pair(dist[next], next));
			}
		}

		// �������� ��� Ž���ϸ鼭 �����Ͽ��⿡ ���� �ݺ������� pq�� ����ġ�� �ּҰ� �Ǵ� ����ġ��� �� �� �ִ�
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}

    return 0;
}