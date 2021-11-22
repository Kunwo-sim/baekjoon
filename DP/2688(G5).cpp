#include <iostream>
using namespace std;

int t;
long long dp[65][10];

void fun() {
    for (int i = 0; i <= 9; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= 64; i++) {
        for (int j = 9; j >= 0; j--) {
            if (j == 9) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    int n;
    fun();
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n][0] << '\n';
    }
    return 0;
}