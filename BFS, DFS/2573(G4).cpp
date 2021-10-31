#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int map[300][300];
int temp[300][300];
int N, M, cnt;
int t;
bool isAllZero = false;
bool visited[300][300];

// temp에서 인접한 0찾기
void melt() {
    isAllZero = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                continue;
            }
            // 0이 아닐 경우 (빙산이 있을 경우)
            else {
                isAllZero = false;
            }
            // 주변 바닷물(0) 탐색
            int nearZero = 0;
            for (int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx >= 0 && ny >= 0 && nx < M && ny < N && map[ny][nx] == 0) {
                    nearZero++;
                }
                temp[i][j] = nearZero;
            }
        }
    }
    // 주변 바닷물 만큼 빙산 크기 감소
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] -= temp[i][j];
            if (map[i][j] < 0) {
                map[i][j] = 0;
            }
        }
    }
}

// bfs로 빙산개수 찾기
void bfs(int sx, int sy) {
    if (visited[sy][sx])
        return;
    visited[sy][sx] = true;
    if (map[sy][sx] == 0)
        return;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
                if (!visited[ny][nx] && map[ny][nx] != 0) {
                    visited[ny][nx] = true;
                    q.push(make_pair(nx, ny));
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

    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while (1)
    {
        t++;
        melt();
        // 빙산이 없으면 (모두 0이면) 0출력
        if (isAllZero) {
            cout << 0;
            break;
        }
        // 초기화
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        // bfs로 빙산 개수 세기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                bfs(j, i);
            }
        }
        // 빙산이 2개 이상이면 출력
        if (cnt >= 2) {
            cout << t;
            break;
        }
    }
    return 0;
}