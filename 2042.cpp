// ���׸�Ʈ Ʈ��

/*#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// ���׸�Ʈ Ʈ�� ����, ���� Ʈ���� ���� �־�� �ϱ� ������ ������ ���
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

// ������ ���� �� ���׸�Ʈ Ʈ�� ����
void update(vector<long long>& a, vector<long long>& tree, int node, int start, int end, int index, long long val) {
	if (index<start || index>end) {
		return;
	}
	if (start == end) {
		a[index] = val; // ������ ��ġ(index) �� ������ ��(value) ���� ����
		tree[node] = val; // a �� �����Ǵ� ���׸�Ʈ Ʈ���� ��� ��ġ�� ����
		return;
	}
	
	update(a, tree, node * 2, start, (start + end) / 2, index, val);
	update(a, tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; // �ؿ��� ���� ���ذ��� �����ذ���
}

// ������ ���ϱ�
long long query(vector<long long>& a, vector<long long>& tree, int node, int start, int end, int s, int e) {	
	if (s > end || e < start) { // ������ ���� ��� ���� ���̸� 0 ����
		return 0;
	}
	if (s <= start && end <= e) { // ������ ���� ��� ������ �����ϸ� �ش� ��� ����
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

	vector <long long> a(n); // N ���� ��
	int h = (int)ceil(log2(2 * n - 1)); // Ʈ�� ����
	int treesize = (1 << h); // ����� ����
	vector <long long> tree(treesize); // ���׸�Ʈ Ʈ��

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

// ����Ʈ��, ���̳ʸ� �ε��� Ʈ��

/*#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable:4996)
long long arr[1000001], tree[1000001];

int n, m, k;

// i ��° �������� ���� ���� ����ϴ� �Լ�
long long prefixSum(int i) {
	long long result = 0;
	while (i > 0) {
		result += tree[i];
		// 0 �� �ƴ� ������ ��Ʈ��ŭ �����鼭 �̵�
		i -= (i & -i);
	}
	return result;
}

// i ��° ���� dif ��ŭ ���ϴ� �Լ�
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
		// ������Ʈ ������ ���
		if (op == 1) {
			int index;
			long long value;
			scanf("%d %lld", &index, &value);
			update(index, value - arr[index]); // �ٲ� ũ��(dif)��ŭ ����
			arr[index] = value; // i ��° ���� value �� ������Ʈ
		}
		// ���� ��(interval sum) ������ ���
		else {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", intervalSum(start, end));
		}
	}
	return 0;
}*/