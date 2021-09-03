#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int premap[30][30];
int nextmap[30][30];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
bool ispossible = true;
bool visited[30][30];
int n, m;

void bfs(int a, int b, int num, int targetnum)
{
	if (visited[a][b])
		return;
	visited[a][b] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		premap[y][x] = targetnum;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n)
			{
				if (!visited[ny][nx] && premap[ny][nx] == num)
				{
					visited[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}

			}
		}
	}
	// bfs 실행 후 같은 지 검사
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (premap[i][j] != nextmap[i][j])
				ispossible = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	// 투약 전 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> premap[i][j];
		}
	}
	// 투약 후 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> nextmap[i][j];
		}
	}
	// 루프 돌면서 확인
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 투약 전 / 후 다르면 bfs
			if (premap[i][j] != nextmap[i][j])
			{
				bfs(i, j, premap[i][j], nextmap[i][j]);
			}
		}
	}
	if (ispossible)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}