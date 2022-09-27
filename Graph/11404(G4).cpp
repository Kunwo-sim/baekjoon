#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n, m;
int dist[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> m;

    // 시작 지점, 도착 지점, 비용
    int start, end, cost;

    // 초기화
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> start >> end >> cost;
        dist[start][end] = min(dist[start][end], cost);
    }

    // 거쳐가는 노드
    for (int k = 1; k <= n; k++)
    {
        // 시작 노드
        for (int i = 1; i <= n; i++)
        {
            // 도착 노드
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << dist[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}