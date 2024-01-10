#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	queue<pair<int, int>> q;
	pair<int, int> p[100], tmp, find;
	
	int TC, N, num, pos, cnt, arr[100];

	cin >> TC;

	while (TC--)
	{
		cin >> N >> pos;

		cnt = 0;
		fill_n(arr, 100, 0);

		while (!q.empty())
		{
			q.pop();
		}

		for (int i = 0; i < N; i++)
		{
			cin >> num;

			p[i].first = num;
			p[i].second = i;
			arr[i] = num;

			if (i == pos)find = p[i];
			q.push(p[i]);
		}

		sort(arr, arr + N, greater<>());

		for(int i = 0; i <N;)
		{
			tmp = q.front();

			if (tmp.first == arr[i])
			{
				cnt++;
				i++;
				q.pop();
				if (tmp.second == find.second) break;
			}						
			else
			{
				q.pop();
				q.push(tmp);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}