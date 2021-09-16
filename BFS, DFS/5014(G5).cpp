#include <iostream>
#include <queue>
using namespace std;

bool visited[1000001];
int F, S, G, U, D;
queue <pair<int, int>> q;

void bfs() {
    q.push(make_pair(S, 0));
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == G) {
            cout << cnt;
            return;
        }
        if (cur + U <= F) {
            if (!visited[cur + U]) {
                visited[cur + U] = true;
                q.push(make_pair(cur + U, cnt + 1));
            }
        }
        if (cur - D >= 1) {
            if (!visited[cur - D]) {
                visited[cur - D] = true;
                q.push(make_pair(cur - D, cnt + 1));
            }
        }
    }
    cout << "use the stairs";
    return;
}

int main() {
    cin >> F >> S >> G >> U >> D;
    bfs();
    return 0;
}