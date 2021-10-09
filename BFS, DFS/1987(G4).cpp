#include <iostream>
#include <algorithm>
using namespace std;

bool mapvisited[20][20];
bool charvisited[26];
char map[20][20];

int R, C;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int maxdepth = 0;

void dfs(int x, int y, int depth) {
    // 방문 처리
    mapvisited[y][x] = true;
    // 알파벳 방문 처리
    charvisited[map[y][x] - 65] = true;
    maxdepth = max(maxdepth, depth);
    for (int i = 0; i < 4; i++) {
        // DFS
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 다음 문자열
        int nc = map[ny][nx] - 65;
        if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
            if (!mapvisited[ny][nx] && !charvisited[nc]) {
                dfs(nx, ny, depth + 1);
                mapvisited[ny][nx] = false;
                charvisited[nc] = false;
            }
        }
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            map[i][j] = s[j];
        }
    }
    dfs(0, 0, 1);
    cout << maxdepth;
    return 0;
}