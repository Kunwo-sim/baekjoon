#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int value[2][100000];
int dp[2][100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> value[i][j];
            }
        }
        // 입력
        dp[0][0] = value[0][0];
        dp[1][0] = value[1][0];
        int result = max(dp[0][0], dp[1][0]);
        if (n >= 2) {
            dp[0][1] = max(value[1][0] + value[0][1], value[0][0]);
            dp[1][1] = max(value[0][0] + value[1][1], value[1][0]);
            result = max(dp[0][1], dp[1][1]);
        }
        // dp 점화식
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + value[0][i];
                    dp[0][i] = max(dp[0][i], dp[1][i - 1] + value[0][i]);
                }
                else {
                    dp[1][i] = max(dp[1][i - 2], dp[0][i - 2]) + value[1][i];
                    dp[1][i] = max(dp[1][i], dp[0][i - 1] + value[1][i]);
                }
                result = max(result, dp[j][i]);
            }
        }
        cout << result << '\n';
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}