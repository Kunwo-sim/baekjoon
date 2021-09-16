#include <iostream>
#include <deque>
using namespace std;
#define MAX 100001

int N, K;
int visited[MAX];

void bfs(int start) {
    deque<int> q;
    q.push_back(start);
    visited[start] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();
        if (cur == K) {
            cout << visited[K];
            return;
        }
        if (cur + 1 < MAX) {
            if (visited[cur + 1] > visited[cur] + 1) {
                visited[cur + 1] = visited[cur] + 1;
                q.push_back(cur + 1);
            }
        }
        if (cur - 1 >= 0) {
            if (visited[cur - 1] > visited[cur] + 1) {
                visited[cur - 1] = visited[cur] + 1;
                q.push_back(cur - 1);
            }
        }
        if (cur * 2 < MAX) {
            if (visited[cur * 2] > visited[cur]) {
                visited[cur * 2] = visited[cur];
                q.push_front(cur * 2);
            }
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < MAX; i++) {
        visited[i] = 987654321;
    }
    bfs(N);
    return 0;
}