#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, K, maxWord = -1;
bool canRead[26] = { 0, };
bool wordCheck[26] = { 0, };
vector<int> v;
vector<string> word;

bool checkRead(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (!canRead[s[i] - 97])return false;
	}
	return true;
}

void countRead() {
	int cnt = 0;

	for (int i = 0; i < word.size(); i++) {	
		if (checkRead(word[i])) {
			cnt++;
		}
	}
	maxWord = max(maxWord, cnt);
}

void combi(int start, vector<int> b) {
	if (b.size() == K) {
		for (int i : b)
			canRead[i] = 1;	
		countRead();
		for (int i : b)
			canRead[i] = 0;
		return;
	}
	for (int i = start + 1; i < v.size(); i++) {
		b.push_back(v[i]);
		combi(i, b);
		b.pop_back();
	}
	return;
}

int main() {
	vector<int> b;
	string w;

	cin >> N >> K;

	canRead['a' - 97] = canRead['c' - 97] = canRead['i' - 97] = canRead['n' - 97] = canRead['t' - 97] = 1;		
	copy(canRead, canRead + 26, wordCheck);
	
	for (int i = 0; i < N; i++) {
		cin >> w;
		w = w.substr(4, w.length() - 8);
		word.push_back(w);

		for (int j = 0; j < w.length(); j++) {
			if (!wordCheck[w[j] - 97]) {
				wordCheck[w[j] - 97] = 1;
				v.push_back(w[j] - 97);
			}
		}		
	}

	if (K < 5) cout << 0;
	else {
		K -= 5;
		if (K >= v.size()) cout << N;
		else {
			combi(-1, b);
			cout << maxWord;
		}
	}
	
	return 0;
}