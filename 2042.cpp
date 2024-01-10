// 세그먼트 트리

/*#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 세그먼트 트리 생성, 실제 트리에 값을 넣어야 하기 때문에 참조자 사용
void init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	if (start == end) {
		tree[node] = a[start];
	}
	else {
		init(a, tree, node * 2, start, (start + end) / 2);
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

// 수정값 있을 시 세그먼트 트리 변경
void update(vector<long long>& a, vector<long long>& tree, int node, int start, int end, int index, long long val) {
	if (index<start || index>end) {
		return;
	}
	if (start == end) {
		a[index] = val; // 수정할 위치(index) 에 수정할 값(value) 으로 변경
		tree[node] = val; // a 에 대응되는 세그먼트 트리의 노드 위치도 변경
		return;
	}
	
	update(a, tree, node * 2, start, (start + end) / 2, index, val);
	update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 밑에서 부터 더해가며 수정해간다
}

// 구간값 구하기
long long query(vector<long long>& a, vector<long long>& tree, int node, int start, int end, int s, int e) {	
	if (s > end || e < start) { // 구간이 현재 노드 범위 밖이면 0 리턴
		return 0;
	}
	if (s <= start && end <= e) { // 구간이 현재 노드 범위를 포함하면 해당 노드 리턴
		return tree[node];
	}
	long long lsum = query(a, tree, node * 2, start, (start + end) / 2, s, e);
	long long rsum = query(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, s, e);	
	return lsum + rsum;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k;

	cin >> n >> m >> k;

	vector <long long> a(n); // N 개의 수
	int h = (int)ceil(log2(2 * n - 1)); // 트리 레벨
	int treesize = (1 << h); // 노드의 개수
	vector <long long> tree(treesize); // 세그먼트 트리

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	init(a, tree, 1, 0, n - 1);

	while (!(m == k && m == 0)) {
		int order;
		cin >> order;

		if (order == 1) {
			m--;
			int index;	long long val;
			cin >> index >> val;
			update(a, tree, 1, 0, n - 1, index - 1, val);
		} else if (order == 2) {
			k--;
			int start, end;
			cin >> start >> end;
			cout << query(a, tree, 1, 0, n - 1, start - 1, end - 1) << "\n";
		}
	}
	return 0;
}*/

// 펜윅트리, 바이너리 인덱스 트리

/*#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
long long arr[1000001], tree[1000001];

int n, m, k;

// i 번째 수까지의 누적 합을 계산하는 함수
long long prefixSum(int i) {
	long long result = 0;
	while (i > 0) {
		result += tree[i];
		// 0 이 아닌 마지막 비트만큼 빼가면서 이동
		i -= (i & -i);
	}
	return result;
}

// i 번째 수를 dif 만큼 더하는 함수
void update(int i, long long dif) {
	while (i <= n) {
		tree[i] += dif;
		i += (i & -i);
	}
}

long long intervalSum(int start, int end) {
	return prefixSum(end) - prefixSum(start - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++) {
		long long x;
		scanf("%lld", &x);
		arr[i] = x;
		update(i, x);
	}
	int count = 0;
	while (count++ < m + k) {
		int op;
		scanf("%d", &op);
		// 업데이트 연산일 경우
		if (op == 1) {
			int index;
			long long value;
			scanf("%d %lld", &index, &value);
			update(index, value - arr[index]); // 바뀐 크기(dif)만큼 적용
			arr[index] = value; // i 번째 수를 value 로 업데이트
		}
		// 구간 합(interval sum) 연산인 경우
		else {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", intervalSum(start, end));
		}
	}
	return 0;
}*/