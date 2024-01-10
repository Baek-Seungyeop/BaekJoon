#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int blank = 1;

	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') blank++;
	}

	if (s[0] == ' ')blank--;
	if (s[s.length() - 1] == ' ')blank--;

	cout << blank;
}