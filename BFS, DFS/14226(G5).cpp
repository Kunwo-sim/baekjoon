#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1024
using namespace std;

int S;

struct node {
    // ȭ�� �̸�Ƽ�� ���� / Ŭ������ ���� �̸�Ƽ�� ���� / �ɸ� �ð�
    int n_emo, n_clip, n_time;
};

bool visited[MAX][MAX];
void bfs() {
    queue<node> q;
    q.push({ 1, 0, 0 }); // �ʱ�ȭ
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
        // Ŭ�����忡 ����
        if (emo < MAX && !visited[emo][emo]) {
            visited[emo][emo] = true;
            q.push({ emo, emo, time + 1 });
        }
        // ȭ�鿡 �ٿ��ֱ�
        if (emo + clip < MAX && !visited[emo + clip][clip]) {
            visited[emo + clip][clip] = true;
            q.push({ emo + clip, clip, time + 1 });
        }
        // �̸�Ƽ�� ����
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