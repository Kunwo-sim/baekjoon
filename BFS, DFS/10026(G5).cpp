#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;

char map[101][101];
bool visited[101][101];
int N;
int colorCnt;
int cnt;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void BFS(int x, int y, bool color)
{
    if (visited[y][x])
        return;

    if (color)
        colorCnt++;
    else
        cnt++;

    visited[y][x] = true;
    queue<pair<int, int>> q;
    q.push({ x, y });

    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        char curC = map[curY][curX];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && !visited[nextY][nextX])
            {
                char nextC = map[nextY][nextX];

                if (nextC == curC || (color == true && curC != 'B' && nextC != 'B'))
                {
                    visited[nextY][nextX] = true;
                    q.push({ nextX, nextY });
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    string input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        for (int j = 0; j < input.size(); j++)
        {
            map[i][j] = input[j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            BFS(j, i, false);
        }
    }

    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            BFS(j, i, true);
        }
    }

    cout << cnt << ' ' << colorCnt;

    return 0;
}