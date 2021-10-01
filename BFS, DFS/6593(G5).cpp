#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

// 동서남북상하
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
// z, y, x
int L, R, C;
char map[30][30][30];
bool visited[30][30][30];

struct pos
{
	int x;
	int y;
	int z;
	int t; // 시간
};

int bfs(int a, int b, int c) {

	memset(visited, 0, sizeof(visited));
	visited[c][b][a] = true;
	queue<pos> q;
	q.push({ a, b, c, 0 });
	while (!q.empty()) {
		int x, y, z, time;
		x = q.front().x;
		y = q.front().y;
		z = q.front().z;
		time = q.front().t;
		q.pop();
		// 도착점 찾으면 return
		if (map[z][y][x] == 'E') {
			return time;
		}
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < C && ny < R && nz < L) {
				if (!visited[nz][ny][nx] && map[nz][ny][nx] != '#') {
					visited[nz][ny][nx] = true;
					q.push({ nx, ny, nz, time + 1 });
				}
			}
		}
	}
	return -1;
}

int main() {
	// 입력
	string str;
	int sz = 0, sy = 0, sx = 0;
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> str;
				for (int k = 0; k < C; k++) {
					if (str[k] == 'S') {
						sz = i;
						sy = j;
						sx = k;
					}
					map[i][j][k] = str[k];
				}
			}
		}
		int ans = bfs(sx, sy, sz);
		// 탈출할 수 없으면
		if (ans == -1) {
			cout << "Trapped!" << '\n';
		}
		else {
			cout << "Escaped in " << ans << " minute(s)." << '\n';
		}
	}
	return 0;
}