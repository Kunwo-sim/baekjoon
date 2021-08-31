#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int N;
int map[20][20];
int dtarr[20][20];
int xshark, yshark;
int sharksize = 2;
int sharkexp;
bool iseat;
int cnt, dcnt;
bool visited[20][20];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int sx, int sy)
{
    dcnt = 0;
    visited[sy][sx] = true;
    //x��ǥ, y��ǥ, �Ÿ�
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(sx, sy), dcnt));
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        dcnt = q.front().second;
        //���� ������ �Ÿ� ���
        if (map[y][x] < sharksize && map[y][x] != 9 && map[y][x] != 0)
        {
            dtarr[y][x] = dcnt;
            iseat = true;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                if (!visited[ny][nx] && map[ny][nx] <= sharksize)
                {
                    visited[ny][nx] = true;
                    q.push(make_pair(make_pair(nx, ny), dcnt + 1));
                }
            }
        }
    }
    return;
}

void fun()
{
    //�迭 �˻�
    while (1)
    {
        iseat = false;
        //���� Ž��
        bfs(xshark, yshark);
        //���� ���� ������ ����
        if (!iseat)
        {
            return;
        }
        //���� �ִٸ� �Ÿ��� ���� ª�� ���� Ž��, ���ٸ� ���� ���� �ִ� ����
        int mindt = 987654321;
        int minx = 0;
        int miny = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (dtarr[i][j] < mindt && dtarr[i][j] != 0)
                {
                    mindt = dtarr[i][j];
                    minx = j;
                    miny = i;
                }
            }
        }
        //�̵�, ���� ó��
        cnt += mindt;
        map[yshark][xshark] = 0;
        //��� �̵�
        map[miny][minx] = 9;
        xshark = minx;
        yshark = miny;
        //��� ũ�� ó��
        sharkexp++;
        if (sharkexp >= sharksize)
        {
            sharksize++;
            sharkexp = 0;
        }
        //�迭 �ʱ�ȭ
        memset(visited, 0, sizeof(visited));
        memset(dtarr, 0, sizeof(dtarr));
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                xshark = j;
                yshark = i;
            }
        }
    }
    fun();
    cout << cnt;
    return 0;
}
