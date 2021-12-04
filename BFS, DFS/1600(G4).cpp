#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
// 말 이동
int hx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int hy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int map[200][200];
bool visited[200][200][30];
int K, W, H;

struct info
{
    int x;
    int y;
    // 말 이동 사용 횟수
    int move;
    // 이동 횟수
    int cnt;
};
int bfs() {
    queue<info> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = true;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int move = q.front().move;
        int cnt = q.front().cnt;
        q.pop();
        // 목적지 도착
        if (x == W - 1 && y == H - 1) {
            return cnt;
        }
        int temp = 1;
        // 말 이동
        if (move < K) {
            for (int i = 0; i < 8; i++) {
                int nx = x + hx[i];
                int ny = y + hy[i];
                if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
                    // 방문하지 않았고, 평지일 때
                    if (!visited[ny][nx][move + 1] && map[ny][nx] == 0) {
                        visited[ny][nx][move + 1] = true;
                        q.push({ nx, ny, move + 1, cnt + 1 });
                    }
                }
            }
        }
        // 원숭이 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
                // 방문하지 않았고, 평지일 때
                if (!visited[ny][nx][move] && map[ny][nx] == 0) {
                    visited[ny][nx][move] = true;
                    q.push({ nx, ny, move, cnt + 1 });
                }
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }
    cout << bfs();
    return 0;
}