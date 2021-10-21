#include <iostream>
#include <string>
#include <queue>
using namespace std;

char map[50][50];
int R, C;
bool visited[50][50];
// 물 확산 체크
bool TimeCheck[2500];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

struct node
{
    int x;
    int y;
    int time;
};

void SpreadWater() {
    // 물이 흐를 곳을 T로 바꿔줌
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == '*') {
                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < C && ny < R && map[ny][nx] == '.') {
                        map[ny][nx] = 'T';
                    }
                }
            }
        }
    }
    // T를 물로 바꿔줌
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'T') {
                map[i][j] = '*';
            }
        }
    }
}

int bfs(int sx, int sy) {
    visited[sy][sx] = true;
    queue<node> q;
    q.push({ sx, sy, 0 });
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int time = q.front().time;
        // 시작 위치 바꿔줌
        map[y][x] = 'S';
        // 해당 time에 확산된 적 없을 때만 물 확산
        if (!TimeCheck[time])
        {
            SpreadWater();
            TimeCheck[time] = true;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < C && ny < R && !visited[ny][nx]) {
                // 비버 굴이면 time 리턴
                if (map[ny][nx] == 'D')
                    return time + 1;
                // 빈 공간이면 이동
                else if (map[ny][nx] == '.')
                {
                    visited[ny][nx] = true;
                    q.push({ nx, ny, time + 1 });
                }
            }
        }
        // 시작 위치 원래대로 돌림
        map[y][x] = '.';
    }
    return -1;
}

int main()
{
    // 입력
    cin >> R >> C;
    string s;
    int sx, sy;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            map[i][j] = s[j];
            if (s[j] == 'S')
            {
                sx = j;
                sy = i;
            }
        }
    }

    int ans = bfs(sx, sy);
    // 도달할 수 없으면 KAKTUS 출력
    if (ans == -1) {
        cout << "KAKTUS";
    }
    else {
        cout << ans;
    }
    return 0;
}