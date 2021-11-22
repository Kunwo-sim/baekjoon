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
    // �θ� �ʱ�ȭ
    for (int i = 1; i <= N; i++) {
        root[i] = i;
    }
    // ����Ǿ� ������ ��ġ��
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
    // �θ� �ٸ���(����Ǿ� ���� ������) NO ���
    //��� �θ� ���ٸ�(����Ǿ� ������) YES ���
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