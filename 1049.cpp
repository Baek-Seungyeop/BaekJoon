#include <iostream>
using namespace std;

int main()
{
	int guitar, model, six[50], one[50], smin, omin, money, rest, r;

	cin >> guitar >> model;

	smin = omin = 1000;
	money = rest = 0;

	for (int i = 0; i < model; i++)
	{
		cin >> six[i] >> one[i];

		smin = min(smin, six[i]);
		omin = min(omin, one[i]);
	}

	if (smin > 6 * omin)
	{
		rest = guitar * omin;
	}
	
	else
	{
		rest = guitar / 6;
		rest = smin * rest;

		r = guitar % 6;

		if (smin > r * omin)
		{
			rest += r * omin;
		}
		else
		{
			rest += smin;
		}
	}
	cout << rest;

	return 0;
}