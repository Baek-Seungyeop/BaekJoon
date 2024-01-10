//#include <iostream>
//#include <string>
//using namespace std;
//
//char map[5][5];
//char visited[5][5];
//int dx[4] = { 0, 1, 0, -1 };
//int dy[4] = { -1, 0, 1, 0 };
//int R, C, K;
//string T;
//
//int go(int y, int x) // dfs
//{
//	if (y == 0 && x == C - 1) { // ���� ����, x, y ��ǥ�� ������ ���� �����̸�
//		if (K == visited[y][x])return 1; // �Ÿ��� K �� ���, ����ġ 1�� ��ȯ
//		return 0;
//	}
//	int ret = 0; // ����ġ�� ���� ������ ����
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = dy[i] + y;
//		int nx = dx[i] + x;
//		if (ny < 0 || ny >= R || nx < 0 || nx >= C || map[ny][nx] == 'T' || visited[ny][nx]) continue;
//		// ���� ������, ��ֹ� T �� �� �� ��ȴ� ���� �湮�� �� ���� ������ ����
//	
//		visited[ny][nx] = visited[y][x] + 1; // �̵��� ��ġ�� ���� ����ġ�� �հ� ���� ����ġ�� ����
//		ret += go(ny, nx);
//		visited[ny][nx] = 0; // �ٽ� �ʱ�ȭ�� ������ �������� ����� ���� üũ�� �� ����
//	}
//	return ret; // ���� ����� ������ ��ȯ
//}
//
//int main() {
//	cin >> R >> C >> K;
//
//	for (int i = 0; i < R; i++) {
//		cin >> T;
//		for (int j = 0; j < C; j++) {	
//			map[i][j] = T[j];
//		}
//	}
//
//	visited[R - 1][0] = 1;
//	cout << go(R - 1, 0) << endl;
//
//	return 0;
//}