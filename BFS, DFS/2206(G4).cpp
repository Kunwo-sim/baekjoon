#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct info
{
    int x;
    int y;
    int wall;
    int cnt;
};
int N, M;
int map[1001][1001];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
bool visited[1001][1001][2];

void bfs() {
    queue<info> q;
    q.push({ 1, 1, 0, 1 });
    visited[1][1][0] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int wall = q.front().wall;
        int cnt = q.front().cnt;
        q.pop();
        if (x == M && y == N)
        {
            cout << cnt;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= M && ny >= 1 && ny <= N) {
                int next = map[ny][nx];
                // 벽 부순적이 없을 때, 방문하지 않았고 벽이면 변수 바꿔주고 push
                if (next == 1 && wall == 0 && !visited[ny][nx][1]) {
                    visited[ny][nx][1] = true;
                    q.push({ nx, ny, 1, cnt + 1 });
                }
                // 벽이 아니고, 방문하지 않았다면 push
                if (next == 0 && !visited[ny][nx][wall]) {
                    visited[ny][nx][wall] = true;
                    q.push({ nx, ny, wall, cnt + 1 });
                }
            }
        }
    }
    cout << -1;
}
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= s.length(); j++) {
            map[i][j] = s[j - 1] - 48;
        }
    }
    bfs();
    return 0;
}