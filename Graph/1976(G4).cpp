#include <iostream>
using namespace std;

int root[201];
int N, M;
int find(int x) {
    if (root[x] == x) {
        return x;
    }
    else {
        return root[x] = find(root[x]);
    }
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    root[y] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    // 부모 초기화
    for (int i = 1; i <= N; i++) {
        root[i] = i;
    }
    // 연결되어 있으면 합치기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            bool Isconnect;
            cin >> Isconnect;
            if (Isconnect) {
                merge(i, j);
            }
        }
    }
    int start, end;
    cin >> start;
    // 부모가 다르면(연결되어 있지 않으면) NO 출려
    //모두 부모가 같다면(연결되어 있으면) YES 출력
    for (int i = 1; i < M; i++) {
        cin >> end;
        if (find(start) != find(end)) {
            cout << "NO";
            return 0;
        }
        start = end;
    }
    cout << "YES";
    return 0;
}