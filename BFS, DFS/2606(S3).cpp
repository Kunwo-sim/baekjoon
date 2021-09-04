#include<iostream>
using namespace std;

bool graph[101][101];
bool visited[101];
int n, m;
int cnt;
void dfs(int node)
{
	if (visited[node])
		return;
	visited[node] = true;
	for (int i = 1; i < 101; i++)
	{
		if (graph[node][i])
		{
			if (!visited[i])
			{
				cnt++;
				dfs(i);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = true;
		graph[b][a] = true;
	}
	dfs(1);
	cout << cnt << endl;
	return 0;
}