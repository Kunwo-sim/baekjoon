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
    // �湮������ return
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
            // ���� 0 �ΰ�� (������ �� ���)
            if (nextcolor == 0) {
                // ���� ����
                if (curcolor == 1) {
                    color[next] = 2;
                }
                else {
                    color[next] = 1;
                }
            }
            // ������ ���� ��쿡�� �̺б׷����� �ƴ�
            else if (nextcolor == curcolor) {
                IsBipartite = false;
                return;
            }
            // �湮���� �ʾҴٸ� push
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
        // �ʱ�ȭ
        IsBipartite = true;
        memset(visited, 0, sizeof(visited));
        memset(color, 0, sizeof(color));
        // �Է�
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