#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
}

const int INF = 100;
int a[10][10], ret = INF, n = 10;
int mp[5];

bool check(int y, int x, int cnt) {
	if (y + cnt > n || x + cnt > n) return false;
	for (int i = y; i < y + cnt; i++) {
		for (int j = x; j < x + cnt; j++) {
			if (a[i][j] == 0) return false;
		}
	}
	return true;
}

void draw(int y, int x, int cnt, int value) {
	for (int i = y; i < y + cnt; i++) {
		for (int j = x; j < x + cnt; j++) {
			a[i][j] = value;
		}
	}
}

void dfs(int y, int x, int cnt) {
	if (x == n) {
		dfs(y + 1, 0, cnt);
		return;
	}
	if (y == n) {
		ret = min(cnt, ret);
		return;
	}
	if (a[y][x] == 0) {
		dfs(y, x + 1, cnt);
		return;
	}
	for (int i = 5; i >= 1; i--) {
		if (mp[i] == 5) continue; 
		// 6��°�� ��� �ݺ����� �ǳʶ�� i�� 1�� ��� dfs�� return ���� y == n ���ǹ��� �������� ���ϰ� �Ѵ�
		if (check(y, x, i)) {
			mp[i]++;
			draw(y, x, i, 0);
			dfs(y, x + i, cnt + 1);
			draw(y, x, i, 1); // �� ����
			mp[i]--; // ������ ����
		}
	}
	return;
}

int main() {
	fast();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0, 0, 0);

	cout << (ret == INF ? -1 : ret) << '\n';
	return 0;
}

