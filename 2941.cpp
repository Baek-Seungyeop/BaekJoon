#include<iostream>
using namespace std;

int main()
{
	string s;
	string Aphabet[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	cin >> s;

	for (int i = 0; i < 8; i++)
	{
		while (1)
		{
			if (s.find(Aphabet[i]) == string::npos) break;
			s.replace(s.find(Aphabet[i]), Aphabet[i].length(), "h");
		}
	}

	cout << s.length();

	return 0;
}