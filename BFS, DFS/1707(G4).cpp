#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> v[20001];
bool visited[20001];
bool IsBipartite;
int color[20001];

void bfs(int start) {
    // 방문했으면 return
    if (visited[start]) {
        return;
    }
    color[start] = 1;
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        int curcolor = color[cur];
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            int nextcolor = color[next];
            // 색깔 0 인경우 (지정안 된 경우)
            if (nextcolor == 0) {
                // 색깔 지정
                if (curcolor == 1) {
                    color[next] = 2;
                }
                else {
                    color[next] = 1;
                }
            }
            // 색깔이 같은 경우에는 이분그래프가 아님
            else if (nextcolor == curcolor) {
                IsBipartite = false;
                return;
            }
            // 방문하지 않았다면 push
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K;
    cin >> K;
    while (K--) {
        // 초기화
        IsBipartite = true;
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        // 입력
        int V, E;
        cin >> V >> E;
        for (int i = 0; i < E; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 1; i < V; i++) {
            bfs(i);
        }
        if (IsBipartite) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
        for (int i = 1; i <= V; i++) {
            v[i].clear();
        }
    }
    return 0;
}