#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int INF = 98765432;
int N, E, v1, v2;
int Dist[801];
vector<pair<int, int>> Vertex[801];

// 다익스트라
void Dijkstra(int Start)
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, Start));
    Dist[Start] = 0;

    while (!PQ.empty())
    {
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        for (int i = 0; i < Vertex[Cur].size(); i++)
        {
            int Next = Vertex[Cur][i].second;
            int nCost = Vertex[Cur][i].first;

            if (Dist[Next] > Cost + nCost)
            {
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
}

// Dist 초기화
void Init() {
    for (int i = 1; i <= N; i++) {
        Dist[i] = INF;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;
    Init();
    int a, b, cost;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> cost;
        Vertex[a].push_back(make_pair(cost, b));
        Vertex[b].push_back(make_pair(cost, a));
    }
    cin >> v1 >> v2;
    Dijkstra(1);
    // S to V1, S to V2
    int StoV1 = Dist[v1];
    int StoV2 = Dist[v2];
    // V1 to V2, V1 to E
    Init();
    Dijkstra(v1);
    int V1toV2 = Dist[v2];
    int V1toE = Dist[E];
    // v2 to E
    int V2toE = Dist[E];
    // S V1 V2 E와 S V2 V1 E 비교
    int ans = min(StoV1 + V1toV2 + V2toE, StoV2 + V1toV2 + V1toE);
    if (ans >= INF) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;
}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;
    Init();
    int a, b, cost;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> cost;
        Vertex[a].push_back(make_pair(cost, b));
        Vertex[b].push_back(make_pair(cost, a));
    }
    cin >> v1 >> v2;
    Dijkstra(1);
    // S to V1, S to V2
    int StoV1 = Dist[v1];
    int StoV2 = Dist[v2];
    // V1 to V2, V1 to E
    Init();
    Dijkstra(v1);
    int V1toV2 = Dist[v2];
    int V1toE = Dist[E];
    // v2 to E
    int V2toE = Dist[E];
    // S V1 V2 E와 S V2 V1 E 비교
    int ans = min(StoV1 + V1toV2 + V2toE, StoV2 + V1toV2 + V1toE);
    if (ans >= INF) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;
}