#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int V, E, K;
int dist[20001];
vector<pair<int, int>> vertex[20001];
// 다익스트라
void Dijkstra(int Start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, Start));
    dist[Start] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < vertex[cur].size(); i++)
        {
            int next = vertex[cur][i].second;
            int nCost = vertex[cur][i].first;
            if (dist[next] > cost + nCost)
            {
                dist[next] = cost + nCost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

void Init() {
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E >> K;
    Init();
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 단방향 연결
        vertex[u].push_back(make_pair(w, v));
    }
    Dijkstra(K);
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    return 0;
}