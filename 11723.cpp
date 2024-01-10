#include <iostream>
#include <string>
using namespace std;

int main() {
	string command;
	int num, M;
	int bitmarsking = 0;
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	cin >> M;

	for (int i = 0; i <M; i++) {
		cin >> command;

		if (command == "all")
			bitmarsking = 0b111111111111111111111;
		else if (command == "empty")
			bitmarsking = 0;
		else {
			cin >> num;

			if (command == "add") {
				// if (bitmarsking & (1 << num)) continue;
				bitmarsking |= (1 << num);
			}
			else if (command == "remove") {
				// if (!(bitmarsking & (1 << num))) continue;
				bitmarsking &= ~(1 << num);
			}
			else if (command == "check") {
				cout << (bitmarsking & (1 << num) ? 1 : 0)<< '\n';	
			}
			else if (command == "toggle") {
				bitmarsking ^= (1 << num);
			}
		}
	}
	return 0;
}