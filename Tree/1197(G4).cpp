#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Parent[10001];

struct Edge
{
    // ����ġ, ����, ��
    int weight;
    int u;
    int v;
};

// �θ� ã��
int Find(int x) {
    if (Parent[x] == x)
        return x;
    else
        return Parent[x] = Find(Parent[x]);
}

// ��ġ��
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y)
        Parent[y] = x;
}

// �θ� ������ Ȯ��
bool IsSameParent(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y)
        return false;
    else
        return true;
}

// ����ġ �������� �������� ����
int myCompare(Edge& a, Edge& b)
{
    return a.weight < b.weight;
}
int main()
{
    ios_base::sync_with_stdio(false);

    // �Է�
    vector<Edge> v;
    int V, E;
    long long ans = 0;
    cin >> V >> E;
    for (int i = 0; i < V; i++)
    {
        Parent[i] = i;
    }
    int a, b, cost;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> cost;
        v.push_back({ cost, a, b });
    }

    // ����ġ �������� �������� ����
    sort(v.begin(), v.end(), myCompare);
    for (int i = 0; i < v.size(); i++) {
        // u, v�� ������� �ʾ��� ���(���� �θ� �ƴҰ��) �������ְ� ����ġ ����
        if (IsSameParent(v[i].u, v[i].v) == false)
        {
            Union(v[i].u, v[i].v);
            ans += v[i].weight;
        }
    }
    cout << ans;
    return 0;
}