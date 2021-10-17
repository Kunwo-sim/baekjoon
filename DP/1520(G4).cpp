#include <iostream>
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int map[500][500];
int dp[500][500];
int M, N, ans;

int dfs(int x, int y) {
    // 도착점이면 1 return
    if (x == N - 1 && y == M - 1) {
        return 1;
    }
    // 탐색한 적이 있으면 도착할 수 있는 경우의 수 반환
    if (dp[y][x] != -1)
        return dp[y][x];
    // 0으로 설정하고 DFS
    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (map[y][x] > map[ny][nx]) {
                dp[y][x] += dfs(nx, ny);
            }
        }
    }
    return dp[y][x];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    ans = dfs(0, 0);
    cout << ans;
    return 0;
}