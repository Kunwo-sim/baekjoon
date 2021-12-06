#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct virus
{
    int x;
    int y;
    int time = 0;
};
int N, M;
int origin_map[50][50];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1 ,1, 0, 0 };
int map[50][50];
int zeroPlace;
int mintime = -1;
bool Vselect[10];
bool visited[50][50];
vector<virus> v;

// 맵 복사
void copymap() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = origin_map[i][j];
        }
    }
}
int bfs() {
    queue<virus> q;
    // 선택받지 않은 바이러스는 map에서 3으로 변경, 선택받은 바이러스는 queue에 넣어주기
    for (int i = 0; i < v.size(); i++) {
        if (!Vselect[i]) {
            map[v[i].y][v[i].x] = 3;
        }
        else {
            q.push({ v[i].x, v[i].y });
            visited[v[i].y][v[i].x] = true;
        }
    }
    int time = 0;
    // 0인 공간 중 아직 바이러스가 확산되지 않는 곳
    int remainingPlace = zeroPlace;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().time;
        if (remainingPlace <= 0)
            return time;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (!visited[ny][nx] && map[ny][nx] != 1) {
                    if (map[ny][nx] == 0)
                        remainingPlace--;
                    map[ny][nx] = 2;
                    visited[ny][nx] = true;
                    q.push({ nx, ny, t + 1 });
                    time = max(time, t + 1);
                }
            }
        }
    }
    return -1;
}
// 바이러스 확산
void SpreadVirus() {
    // map 초기화, 방문 초기화
    copymap();
    memset(visited, 0, sizeof(visited));
    // bfs
    int time = bfs();
    // 최소갱신
    if (time != -1) {
        if (mintime == -1) {
            mintime = time;
        }
        else {
            mintime = min(mintime, time);
        }
    }
}

// 바이러스 선택
void SelectVirus(int cnt, int idx) {
    // M개 만큼 고르면 확산
    if (cnt == M) {
        SpreadVirus();
        return;
    }
    for (int i = idx; i < v.size(); i++) {
        Vselect[i] = true;
        SelectVirus(cnt + 1, i + 1);
        Vselect[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> origin_map[i][j];
            if (origin_map[i][j] == 2) {
                v.push_back({ j, i });
            }
            else if (origin_map[i][j] == 0) {
                zeroPlace++;
            }
        }
    }
    SelectVirus(0, 0);
    cout << mintime;
    return 0;
}