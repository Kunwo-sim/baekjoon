#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int N, K, L;
deque<pair<int, int>> dq;
vector<int> vtime;
vector<char> vdir;
int map[100][100];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int dummy(int sx, int sy)
{
    int dir = 0;
    int cnt = 0;
    int x, y;
    int idx = 0;
    dq.push_back(make_pair(sx, sy));
    while (1)
    {
        x = dq.front().first;
        y = dq.front().second;
        map[y][x] = 2;
        cnt++;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        //게임 끝
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[ny][nx] == 2)
        {
            return cnt;
        }
        else
        {
            dq.push_front(make_pair(nx, ny));
            // 사과 있으면 그대로, 없으면 dq 끝에서 pop 해주기
            if (map[ny][nx] != 1)
            {
                int xend, yend;
                xend = dq.back().first;
                yend = dq.back().second;
                map[yend][xend] = 0;
                dq.pop_back();
            }
            //시간 확인 후 방향 변경
            if (cnt == vtime[idx])
            {
                if (vdir[idx] == 'L')
                {
                    dir += 3;
                    dir %= 4;
                }
                else
                {
                    dir += 1;
                    dir %= 4;
                }
                if (idx < vtime.size() - 1)
                {
                    idx++;
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> K;
    // 사과
    for (int i = 0; i < K; i++)
    {
        int applex, appley;
        cin >> applex >> appley;
        map[applex - 1][appley - 1] = 1;
    }
    cin >> L;
    // 명령
    for (int i = 0; i < L; i++)
    {
        int t;
        char d;
        cin >> t >> d;
        vtime.push_back(t);
        vdir.push_back(d);
    }
    cout << dummy(0, 0);
    return 0;
}