#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Parent[10001];

struct Edge
{
    // 가중치, 시작, 끝
    int weight;
    int u;
    int v;
};

// 부모 찾기
int Find(int x) {
    if (Parent[x] == x)
        return x;
    else
        return Parent[x] = Find(Parent[x]);
}

// 합치기
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y)
        Parent[y] = x;
}

// 부모가 같은지 확인
bool IsSameParent(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y)
        return false;
    else
        return true;
}

// 가중치 기준으로 오름차순 정렬
int myCompare(Edge& a, Edge& b)
{
    return a.weight < b.weight;
}
int main()
{
    ios_base::sync_with_stdio(false);

    // 입력
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

    // 가중치 기준으로 오름차순 정렬
    sort(v.begin(), v.end(), myCompare);
    for (int i = 0; i < v.size(); i++) {
        // u, v가 연결되지 않았을 경우(같은 부모가 아닐경우) 연결해주고 가중치 증가
        if (IsSameParent(v[i].u, v[i].v) == false)
        {
            Union(v[i].u, v[i].v);
            ans += v[i].weight;
        }
    }
    cout << ans;
    return 0;
}