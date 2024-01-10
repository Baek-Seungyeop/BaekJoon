#include <iostream>
using namespace std;

int main()
{
	int x1, x2, x3, y1, y2, y3;
	bool circle, line;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	circle = (y2 - y1) * (x3 - x2) > (x2 - x1) * (y3 - y2);
	line = (y2 - y1) * (x3 - x2) == (x2 - x1) * (y3 - y2);

	if (circle)cout << "-1";
	else if (line)cout << "0";
	else cout << "1";

	return 0;
}