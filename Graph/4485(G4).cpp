#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int N;
int Rupee[125][125];
int Sum[125][125];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

struct node
{
    int rupee;
    int x;
    int y;
    // 오름차순 정렬
    bool operator<(const node& i) const {
        return rupee > i.rupee;
    }
};

void Dijkstra()
{
    priority_queue<node> PQ;
    PQ.push({ Rupee[0][0], 0, 0 });
    Sum[0][0] = Rupee[0][0];
    while (!PQ.empty())
    {
        int rupee = PQ.top().rupee;
        int x = PQ.top().x;
        int y = PQ.top().y;
        PQ.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nRupee = Rupee[ny][nx];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (Sum[ny][nx] > rupee + nRupee) {
                    Sum[ny][nx] = rupee + nRupee;
                    PQ.push({ Sum[ny][nx], nx, ny });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 0;
    while (1) {
        cnt++;
        cin >> N;
        if (N == 0) {
            break;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> Rupee[i][j];
                Sum[i][j] = INF;
            }
        }
        Dijkstra();
        cout << "Problem " << cnt << ": " << Sum[N - 1][N - 1] << '\n';
    }
    return 0;
}