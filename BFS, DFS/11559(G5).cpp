#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

char map[12][6];
bool ispuyo[12][6];
bool visited[12][6];
bool ischanged;
bool ismovable;
int combo;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int sx, int sy, char color)
{
    if (visited[sy][sx])
        return;
    int puyosize = 1;
    visited[sy][sx] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    //����� 4�̻��̸� .���� ������ֱ� ���� queue
    queue<pair<int, int>> savepuyo;
    savepuyo.push(make_pair(sx, sy));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx <= 5 && ny >= 0 && ny <= 11)
            {
                if (!visited[ny][nx] && map[ny][nx] == color)
                {
                    visited[ny][nx] = true;
                    q.push(make_pair(nx, ny));
                    puyosize++;
                    savepuyo.push(make_pair(nx, ny));
                }
            }
        }
    }
    if (puyosize >= 4)
    {
        ischanged = true;
        while (!savepuyo.empty())
        {
            int px = savepuyo.front().first;
            int py = savepuyo.front().second;
            ispuyo[py][px] = true;
            savepuyo.pop();
        }
    }
}
int main()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
            cin >> map[i][j];
    }
    while (1)
    {
        ischanged = false;
        memset(visited, 0, sizeof(visited));
        memset(ispuyo, 0, sizeof(ispuyo));
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                //. �̸� �湮ó��, ���ڸ� �� ���� BFS
                if (map[i][j] == '.')
                {
                    visited[i][j] = true;
                }
                else
                {
                    bfs(j, i, map[i][j]);
                }
            }
        }
        //��ȭ ������ ��
        if (!ischanged)
            break;
        combo++;
        //ispuyo�ΰ͵� .���� �ٲ��ֱ�
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (ispuyo[i][j])
                {
                    map[i][j] = '.';
                }
            }
        }
        //�Ʒ�ĭ .�� �ѿ�� ������ �б�
        while (1)
        {
            ismovable = false;
            for (int i = 11; i >= 1; i--)
            {
                for (int j = 5; j >= 0; j--)
                {
                    if (map[i][j] == '.' && map[i - 1][j] != '.')
                    {
                        map[i][j] = map[i - 1][j];
                        map[i - 1][j] = '.';
                        ismovable = true;
                    }
                }
            }
            if (!ismovable)
                break;
        }
    }
    //���� ���
    cout << combo;
    return 0;
}