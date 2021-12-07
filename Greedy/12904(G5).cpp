#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;

int main() {
    cin >> S >> T;
    // T를 S로 만듦, 길이 같아질 때 까지
    while (T.length() > S.length()) {
        if (T.back() == 'A') {
            T.pop_back();
        }
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }

    if (S == T) {
        cout << 1;
    }
    else {
        cout << 0;
    }
    return 0;
}