#include <iostream>
using namespace std;

bool isGroup(string word)
{
	bool check[26] = { 0, };
	int idx;

	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] == word[i + 1])continue;
		idx = (int)word[i] - 97;
		if (check[idx] == 0)check[idx] = 1;
		else return false;
	}
	return true;
}

int main()
{
	string word;
	int n, cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> word;

		if (isGroup(word))cnt++;
	}
	cout << cnt;

	return 0;
}