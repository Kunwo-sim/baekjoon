#include <iostream>
using namespace std;

// 명령 개수, 북남서동 확률
int N;
double proArr[4];
double simple;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool visited[100][100];
void dfs(int x, int y, double probaility, int cnt) {
    // 경로 겹치면 return
    if (visited[y][x]) {
        return;
    }
    visited[y][x] = true;
    // cnt만큼 움직였는데 겹치지 않았으면 simple에 지금까지의 확률 더해주기
    if (cnt == N) {
        simple += probaility;
        visited[y][x] = false;
        return;
    }
    // 북남서동 확인
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny, probaility * proArr[i], cnt + 1);
    }
    visited[y][x] = false;
}
int main()
{
    cout << fixed;
    cout.precision(18);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < 4; i++) {
        double prob;
        cin >> prob;
        proArr[i] = prob / 100.0;
    }
    dfs(50, 50, 1, 0);
    cout << simple;
    return 0;
}