#include <iostream>
using namespace std;

int R, C, T;
int CleanUp = -1;
int CleanDown = -1;
int map[50][50];
int temp[50][50];
int ans = 0;

// ���� Ȯ���ϱ�
void SpreadDust() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] != -1 && map[i][j] != 0) {
                int dust = map[i][j] / 5;
                // ��
                if (i > 0 && map[i - 1][j] != -1) {
                    temp[i - 1][j] += dust;
                    map[i][j] -= dust;
                }
                // ��
                if (i + 1 < R && map[i + 1][j] != -1) {
                    temp[i + 1][j] += dust;
                    map[i][j] -= dust;
                }
                // ��
                if (j > 0 && map[i][j - 1] != -1) {
                    temp[i][j - 1] += dust;
                    map[i][j] -= dust;
                }
                // ��
                if (j + 1 < C && map[i][j + 1] != -1) {
                    temp[i][j + 1] += dust;
                    map[i][j] -= dust;
                }
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] += temp[i][j];
            temp[i][j] = 0;
        }
    }
}

// ����û���� �۵�
void Purifier(int Up, int Down) {
    // ���� �ݽð�
    for (int i = Up - 1; i >= 1; i--) {
        map[i][0] = map[i - 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        map[0][i] = map[0][i + 1];
    }
    for (int i = 0; i < Up; i++) {
        map[i][C - 1] = map[i + 1][C - 1];
    }
    for (int i = C - 1; i >= 2; i--) {
        map[Up][i] = map[Up][i - 1];
    }
    map[Up][1] = 0;
    // �Ʒ��� �ð�
    for (int i = Down + 1; i < R - 1; i++) {
        map[i][0] = map[i + 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        map[R - 1][i] = map[R - 1][i + 1];
    }
    for (int i = R - 1; i > Down; i--) {
        map[i][C - 1] = map[i - 1][C - 1];
    }
    for (int i = C - 1; i >= 2; i--) {
        map[Down][i] = map[Down][i - 1];
    }
    map[Down][1] = 0;
}

// ���� �� ���
void CalSum() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // ����û���Ⱑ �ƴ� ��쿡�� ����
            if (map[i][j] != -1) {
                ans += map[i][j];
            }
        }
    }
}

int main()
{
    // �Է�
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            // -1�� ��� û�ұ� ��ġ ����
            if (map[i][j] == -1) {
                if (CleanUp == -1) {
                    CleanUp = i;
                }
                else {
                    CleanDown = i;
                }
            }
        }
    }

    while (T--)
    {
        // ���� Ȯ��
        SpreadDust();
        // ����û���� �۵�
        Purifier(CleanUp, CleanDown);
    }
    CalSum();
    cout << ans;
    return 0;
}