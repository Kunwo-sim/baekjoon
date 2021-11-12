#include <iostream>
using namespace std;

// ��� ����, �ϳ����� Ȯ��
int N;
double proArr[4];
double simple;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool visited[100][100];
void dfs(int x, int y, double probaility, int cnt) {
    // ��� ��ġ�� return
    if (visited[y][x]) {
        return;
    }
    visited[y][x] = true;
    // cnt��ŭ �������µ� ��ġ�� �ʾ����� simple�� ���ݱ����� Ȯ�� �����ֱ�
    if (cnt == N) {
        simple += probaility;
        visited[y][x] = false;
        return;
    }
    // �ϳ����� Ȯ��
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