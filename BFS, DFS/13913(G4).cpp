#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define max 1000001

int N, K;
int parent[max];
bool visited[max];

// ���� ��ġ�� �ɸ� �ð�
struct node
{
    int cur;
    int time;
};

void bfs(int start) {
    queue<node> q;
    q.push({ start, 0 });
    while (!q.empty()) {
        int cur = q.front().cur;
        int time = q.front().time;
        q.pop();
        // ������ ���� �ϸ� ����
        if (cur == K) {
            cout << time << endl;
            return;
        }
        // �ش� ������ ó�� �湮�ϴ� ��� �θ� ���� �� �湮 ó��
        if (cur * 2 < max) {
            if (!visited[cur * 2]) {
                visited[cur * 2] = true;
                q.push({ cur * 2, time + 1 });
                parent[cur * 2] = cur;
            }
        }
        if (cur + 1 < max) {
            if (!visited[cur + 1]) {
                visited[cur + 1] = true;
                q.push({ cur + 1, time + 1 });
                parent[cur + 1] = cur;
            }
        }
        if (cur - 1 >= 0) {
            if (!visited[cur - 1]) {
                visited[cur - 1] = true;
                q.push({ cur - 1, time + 1 });
                parent[cur - 1] = cur;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    bfs(N);
    vector<int> v;
    while (1) {
        // �� -> �������� ��� ã���� �ö󰡱�
        v.push_back(K);
        if (K == N) {
            break;
        }
        K = parent[K];
    }
    // �տ�������(����������) ���
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    return 0;
}