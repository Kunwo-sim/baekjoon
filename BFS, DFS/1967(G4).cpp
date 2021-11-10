#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct node
{
    // ���� ��ȣ
    int vertex;
    // ���� �Ÿ�
    int dist;
};

vector<node> v[10001];
bool visited[10001];
int n, maxnode, maxdist;

void dfs(int cur, int dist) {
    if (visited[cur])
        return;
    visited[cur] = true;
    // �Ÿ� ����
    if (dist > maxdist) {
        maxdist = dist;
        maxnode = cur;
    }
    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i].vertex;
        int nextdist = v[cur][i].dist + dist;
        dfs(next, nextdist);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // �Է�
    cin >> n;
    int a, b, d;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> d;
        v[a].push_back({ b, d });
        v[b].push_back({ a, d });
    }
    // ���� �������� ���� �� ���� ã��
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxdist = 0;
    // ���� �� �������� �ٸ� ���� �� ���� ã��
    dfs(maxnode, 0);
    cout << maxdist;
    return 0;
}