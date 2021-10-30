#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int map[100][100];
int N, M, cnt;
bool visited[100][100];
bool Isreach = false;

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 목적지 도달시 return
        if (x == M - 1 && y == N - 1) {
            cout << cnt;
            Isreach = true;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
                // 벽을 0으로 바꿔주고 방문처리
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    if (map[ny][nx] == 0) {
                        q.push(make_pair(nx, ny));
                    }
                    else {
                        map[ny][nx] = 0;
                    }
                }
            }
        }
    }
    cnt++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - 48;
        }
    }
    while (1)
    {
        memset(visited, 0, sizeof(visited));
        bfs();
        // 도달할 수 있을 때 까지 반복, 벽 허뭄
        if (Isreach)
            break;
    }
    return 0;
}