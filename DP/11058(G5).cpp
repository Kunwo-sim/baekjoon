#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= 5; i++) {
        dp[i] = i;
    }
    for (int i = 6; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j < 4; j++) {
            dp[i] = max(dp[i], dp[i - 2 - j] * (j + 1));
        }
    }
    cout << dp[N];
    return 0;
}