BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[14], mal[4], n = 10;
int v[104]; // ����
const int MAL = 4;
vector<int> adj[54]; // ������ ��

int move(int here, int cnt) {
	if (here == 100) return 100;
	if (adj[here].size() >= 2) {
		here = adj[here][1]; 
		cnt--;
	}
	if (cnt) {
		queue<int>q;
		q.push(here);
		int there;
		while (q.size()) {
			int x = q.front(); q.pop();

			there = adj[x][0];
			q.push(there);
			if (there == 100) break;
			cnt--;
			if (cnt == 0) break;
		}
		return there;
	}
	else return here;
}

bool ismal(int mal_idx, int idx) {
	if (mal_idx == 100) return false;
	for (int i = 0; i < MAL; i++) {
		if (i == idx) continue;
		if (mal[i] == mal_idx) return true;
	}
	return false;
}

void add(int here, int there) {
	adj[here].push_back(there);
}

void setmap() {
	for (int i = 0; i < 20; i++) add(i, i + 1); // adj[0] = 1, ..., adj[19] = 20
	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(15, 29); add(29, 30); add(30, 31); add(31, 24);

	add(10, 27); add(27, 28); add(28, 24); add(24, 25);
	add(25, 26); add(26, 20); add(20, 100);

	v[1] = 2; v[2] = 4; v[3] = 6; v[4] = 8; v[5] = 10;
	v[6] = 12; v[7] = 14; v[8] = 16; v[9] = 18; v[10] = 20;
	v[11] = 22; v[12] = 24; v[13] = 26; v[14] = 28; v[15] = 30;
	v[16] = 32; v[17] = 34; v[18] = 36; v[19] = 38; v[20] = 40;
	v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25;
	v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35;
	v[29] = 28; v[30] = 27; v[31] = 26;
}

int go(int here) {
	if (here == n) return 0;
	int ret = 0; // ����
	for (int i = 0; i < MAL; i++) {
		int tmp_idx = mal[i];
		int mal_idx = move(tmp_idx, a[here]);
		if (ismal(mal_idx, i)) continue;
		mal[i] = mal_idx;
		ret = max(ret, go(here + 1) + v[mal_idx]);
		mal[i] = tmp_idx;
	}
	// cout << "ret : " << ret << '\n';
	return ret;
}

int main() {
	/*ios_base::sync_with_stdio(false);
	cin.tie(null); cout.tie(null);*/
	setmap();
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << go(0) << "\n";
	return 0;
}

/*
����� �� : 4 ^ 10
10���� �ֻ��� ���ڸ�ŭ 4���� ���� �̵��ϴ� ����̱� ������ 4��10
*/

���� ���� ��Ʈ�� ��ȯ

#include <iostream>
using namespace std;

const int board[33][6] = {
	{0, 1, 2, 3, 4, 5}, // �ش� board�� ����, 1 ~ 5ĭ �̵� �� index ��ġ
	{2, 2, 3, 4, 5, 6},
	{4, 3, 4, 5, 6, 7},
	{6, 4, 5, 6, 7, 8},
	{8, 5, 6, 7, 8, 9},
	{10, 21, 22, 23, 24, 25},
	{12, 7, 8, 9, 10, 11},
	{14, 8, 9, 10, 11, 12},
	{16, 9, 10, 11, 12, 13},
	{18, 10, 11, 12, 13, 14},
	{20, 27, 28, 24, 25, 26},
	{22, 12, 13, 14, 15, 16},
	{24, 13, 14, 15, 16, 17},
	{26, 14, 15, 16, 17, 18},
	{28, 15, 16, 17, 18, 19},
	{30, 29, 30, 31, 24, 25},
	{32, 17, 18, 19, 20, 32},
	{34, 18, 19, 20, 32, 32},
	{36, 19, 20, 32, 32, 32},
	{38, 20, 32, 32, 32, 32},
	{40, 32, 32, 32, 32, 32},
	{13, 22, 23, 24, 25, 26},
	{16, 23, 24, 25, 26, 20},
	{19, 24, 25, 26, 20, 32},
	{25, 25, 26, 20, 32, 32},
	{30, 26, 20, 32, 32, 32},
	{35, 20, 32, 32, 32, 32},
	{22, 28, 24, 25, 26, 20},
	{24, 24, 25, 26, 20, 32},
	{28, 30, 31, 24, 25, 26},
	{27, 31, 24, 25, 26, 20},
	{26, 24, 25, 26, 20, 32},
	{0, 32, 32, 32, 32, 32}
};

int input[10];

int getScore(int state) {
	int ret = 0;
	bool visited[33] = { false, };
	int pos[4] = { 0, };
	for (int turn = 0; turn < 10; turn++) {
		int move = input[turn];
		int horse = (state >> (turn * 2)) & 0x03;
		int& curPos = pos[horse];
		int nextPos = board[curPos][move];
		int score = board[nextPos][0];

		if (visited[nextPos] && nextPos != 32) {
			return -1;
		}

		ret += score;
		visited[curPos] = false;
		visited[nextPos] = true;
		curPos = nextPos;
	}

	return ret;
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> input[i];
	}

	int result = 0;

	for (int state = 0; state < (1 << 20); state++) {
		result = max(result, getScore(state));
	}
	
	cout << result;

	return 0;
}