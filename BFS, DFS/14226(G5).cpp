#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1024
using namespace std;

int S;

struct node {
    // 화면 이모티콘 개수 / 클립보드 저장 이모티콘 개수 / 걸린 시간
    int n_emo, n_clip, n_time;
};

bool visited[MAX][MAX];
void bfs() {
    queue<node> q;
    q.push({ 1, 0, 0 }); // 초기화
    visited[1][0] = true;
    while (!q.empty()) {
        int emo = q.front().n_emo;
        int clip = q.front().n_clip;
        int time = q.front().n_time;
        q.pop();
        if (emo == S) {
            cout << time;
            return;
        }
        // 클립보드에 저장
        if (emo < MAX && !visited[emo][emo]) {
            visited[emo][emo] = true;
            q.push({ emo, emo, time + 1 });
        }
        // 화면에 붙여넣기
        if (emo + clip < MAX && !visited[emo + clip][clip]) {
            visited[emo + clip][clip] = true;
            q.push({ emo + clip, clip, time + 1 });
        }
        // 이모티콘 삭제
        if (emo > 1 && !visited[emo - 1][clip]) {
            visited[emo - 1][clip] = true;
            q.push({ emo - 1, clip, time + 1 });
        }
    }

}
int main() {
    cin >> S;
    bfs();
    return 0;
}