//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//typedef long long ll; // long long 자료형 이름 재정의
//ll n, k, ret, temp1, temp;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> n >> k;
//	vector<pair<ll, ll>> v(n); // 보석
//	vector<ll> vv(k); // 가방
//	for (int i = 0; i < n; i++) {
//		cin >> v[i].first >> v[i].second; // weight, price
//	}
//	for (int i = 0; i < k; i++) cin >> vv[i]; // bag_capacity
//	sort(v.begin(), v.end());
//	sort(vv.begin(), vv.end());
//	priority_queue<ll> pq; // 우선순위 큐
//
//	int j = 0;
//	for (int i = 0; i < k; i++) {
//		while (j < n && v[j].first <= vv[i]) pq.push(v[j++].second);
//		// 보석의 수보다 적고 i 번째 가방의 무게보다 작을 때 까지 보석의 가격 push
//		if (pq.size()) {
//			ret += pq.top(); pq.pop(); // 우선순위에 있는 값을 pop -> 가방에 넣은 행위
//		}
//	}
//	cout << ret << "\n";
//	return 0;
//}