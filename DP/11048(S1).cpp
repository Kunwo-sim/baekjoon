#include <iostream>
#include <algorithm>
using namespace std;

int map[1000][1000];
int dp[1000][1000];
int N, M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            dp[i][j] = map[i][j];
            if (i - 1 >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + map[i][j]);
            }
            if (j - 1 >= 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + map[i][j]);
            }
        }
    }
    cout << dp[N - 1][M - 1];
    return 0;
}