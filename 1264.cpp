#include <iostream>
#include <string>
using namespace std;

bool check(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
	{
		return true;
	}
	return false;
}

int main()
{
	string sentence;
	int cnt;
	while (1)
	{
		getline(cin, sentence);
		cnt = 0;

		if (sentence[0] == '#') break;

		for (int i = 0; i < sentence.length(); i++)
		{
			if (check(sentence[i]))cnt++;
		}
		cout << cnt << endl;
	}
}