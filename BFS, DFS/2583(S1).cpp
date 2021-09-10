#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int M, N, K;
int map[100][100];
bool visited[100][100];
// ����
int cnt;
// ������ ����
int width;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
vector<int> v;

void bfs(int fx, int fy)
{
	// �湮������ return
	if (visited[fy][fx])
		return;
	visited[fy][fx] = true;
	// 0�� �ƴ϶�� return
	if (map[fy][fx] == 1)
		return;
	queue<pair<int, int>> q;
	q.push(make_pair(fx, fy));
	width = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (map[y][x] == 0)
		{
			width++;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M)
				{
					if (!visited[ny][nx])
					{
						visited[ny][nx] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	// 0�� �湮�������Ƿ� cnt++, ���� ũ�� ����
	cnt++;
	v.push_back(width);
}
int main()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		for (int j = sy; j < ey; j++)
		{
			for (int k = sx; k < ex; k++)
			{
				map[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bfs(j, i);
		}
	}
	// ����
	sort(v.begin(), v.end());
	cout << cnt << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	return 0;
}