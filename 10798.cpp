#include <iostream>
using namespace std;

int main() {
    char word[5][16] = {0, };

    for (int i = 0; i < 5; i++) {
        cin >> word[i];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (word[j][i] != 0) {
                cout << word[j][i];
            }
        }
    }
}