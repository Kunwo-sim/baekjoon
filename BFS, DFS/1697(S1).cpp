#include <iostream>
#include <queue>
using namespace std;
#define max 1000001

int N, K;
bool visited[max];
void bfs(int start, int c) {
    queue<pair<int, int>> q;
    q.push(make_pair(start, c));
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == K) {
            cout << cnt;
            return;
        }
        if (cur * 2 < max) {
            if (!visited[cur * 2]) {
                visited[cur * 2] = true;
                q.push(make_pair(cur * 2, cnt + 1));
            }
        }
        if (cur + 1 < max) {
            if (!visited[cur + 1]) {
                visited[cur + 1] = true;
                q.push(make_pair(cur + 1, cnt + 1));
            }
        }
        if (cur - 1 >= 0) {
            if (!visited[cur - 1]) {
                visited[cur - 1] = true;
                q.push(make_pair(cur - 1, cnt + 1));
            }
        }
    }
}

int main() {
    cin >> N >> K;
    bfs(N, 0);
    return 0;
}