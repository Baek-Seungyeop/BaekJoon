//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//typedef long long ll; // long long �ڷ��� �̸� ������
//ll n, k, ret, temp1, temp;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> n >> k;
//	vector<pair<ll, ll>> v(n); // ����
//	vector<ll> vv(k); // ����
//	for (int i = 0; i < n; i++) {
//		cin >> v[i].first >> v[i].second; // weight, price
//	}
//	for (int i = 0; i < k; i++) cin >> vv[i]; // bag_capacity
//	sort(v.begin(), v.end());
//	sort(vv.begin(), vv.end());
//	priority_queue<ll> pq; // �켱���� ť
//
//	int j = 0;
//	for (int i = 0; i < k; i++) {
//		while (j < n && v[j].first <= vv[i]) pq.push(v[j++].second);
//		// ������ ������ ���� i ��° ������ ���Ժ��� ���� �� ���� ������ ���� push
//		if (pq.size()) {
//			ret += pq.top(); pq.pop(); // �켱������ �ִ� ���� pop -> ���濡 ���� ����
//		}
//	}
//	cout << ret << "\n";
//	return 0;
//}