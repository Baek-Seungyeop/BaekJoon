#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int ConvertIndex(int i)
{
	if (i == 4000)return 0;
	else return i - 4000;
}

double Avg(int* num, int N)
{
	double avg = 0.0;

	for (int i = 0; i < N; i++)
	{
		avg += num[i];
	}
	avg /= N;
	avg = round(avg);

	return avg;
}

int Mid(int* num, int N)
{
	return num[N / 2];
}

int Mod(int* num, int N)
{
	int mod[8001] = { 0, }, m = 0, mode;
	bool second = false;

	for (int i = 0; i < N; i++)
	{
		if (num[i] < 0) mod[4000 - (-num[i])]++;
		else if (num[i] == 0)mod[4000]++;
		else mod[4000 + num[i]]++;
	}

	for (int i = 0; i < 8001; i++)
	{
		m = max(mod[i], m);
	}

	for (int i = 0; i < 8001; i++)
	{
		if (m == mod[i])
		{
			if (second)
			{
				mode = ConvertIndex(i);
				break;
			}
			second = true;
			mode = ConvertIndex(i);
		}
	}
	return mode;
}

int Rng(int* num, int N)
{
	return num[N - 1] - num[0];
}

int main()
{
	int N, *num;

	cin >> N;

	num = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	sort(num, num + N);

	cout << (int)Avg(num, N) << endl;
	cout << Mid(num, N) << endl;
	cout << Mod(num, N) << endl;
	cout << Rng(num, N);

	delete[]num;

	return 0;
}