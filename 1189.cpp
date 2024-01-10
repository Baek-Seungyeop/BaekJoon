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
//	if (y == 0 && x == C - 1) { // 종료 조건, x, y 좌표가 문제의 종료 지점이며
//		if (K == visited[y][x])return 1; // 거리가 K 인 경우, 가중치 1을 반환
//		return 0;
//	}
//	int ret = 0; // 가중치의 합을 저장할 변수
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = dy[i] + y;
//		int nx = dx[i] + x;
//		if (ny < 0 || ny >= R || nx < 0 || nx >= C || map[ny][nx] == 'T' || visited[ny][nx]) continue;
//		// 문제 조건인, 장애물 T 와 한 번 들렸던 곳은 방문할 수 없는 조건을 적용
//	
//		visited[ny][nx] = visited[y][x] + 1; // 이동할 위치에 이전 가중치의 합과 현재 가중치를 저장
//		ret += go(ny, nx);
//		visited[ny][nx] = 0; // 다시 초기화를 함으로 여러가지 경우의 수를 체크할 수 있음
//	}
//	return ret; // 최종 경우의 가짓수 반환
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