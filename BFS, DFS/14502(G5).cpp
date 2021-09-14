#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n, m;
int premap[8][8];
int nextmap[8][8];
int cnt;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int safefield;
int maxsafe;
bool check[64];
bool visited[8][8];

void copymap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			nextmap[i][j] = premap[i][j];
		}
	}
}

void bfs(int sx, int sy)
{
	if (visited[sy][sx])
		return;
	visited[sy][sx] = true;
	queue<pair<int, int>> q;
	queue<pair<int, int>> virusq;
	q.push(make_pair(sx, sy));
	if (nextmap[sy][sx] == 0)
		virusq.push(make_pair(sx, sy));
	bool isvirus = false;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (!isvirus)
			if (nextmap[y][x] == 2)
				isvirus = true;
		if (nextmap[y][x] != 1)
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n)
				{
					if (!visited[ny][nx] && nextmap[ny][nx] != 1)
					{
						visited[ny][nx] = true;
						if (nextmap[ny][nx] == 0)
							virusq.push(make_pair(nx, ny));
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	// 바이러스 있으면 확산
	if (isvirus)
	{
		while (!virusq.empty())
		{
			int x = virusq.front().first;
			int y = virusq.front().second;
			virusq.pop();
			nextmap[y][x] = 2;
		}
	}
}

void wall()
{
	if (cnt == 3)
	{
		memset(visited, 0, sizeof(visited));
		copymap();
		safefield = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				bfs(j, i);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (nextmap[i][j] == 0)
					safefield++;
			}
		}
		maxsafe = max(maxsafe, safefield);
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (premap[i][j] == 0)
				{
					premap[i][j] = 1;
					cnt++;
					wall();
					cnt--;
					premap[i][j] = 0;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> premap[i][j];
		}
	}
	wall();
	cout << maxsafe;
	return 0;
}