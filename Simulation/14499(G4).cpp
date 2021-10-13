#include <iostream>
using namespace std;

struct Dice
{
    // �ϳ����� ���Ʒ�
    int N = 0;
    int S = 0;
    int E = 0;
    int W = 0;
    int Top = 0;
    int Bottom = 0;
};
int map[20][20];
int N, M, y, x, K;

// �ش� �������� �ֻ��� ������
void MoveE(Dice& dice) {
    int temp = dice.Top;
    dice.Top = dice.W;
    dice.W = dice.Bottom;
    dice.Bottom = dice.E;
    dice.E = temp;
}

void MoveW(Dice& dice) {
    int temp = dice.Top;
    dice.Top = dice.E;
    dice.E = dice.Bottom;
    dice.Bottom = dice.W;
    dice.W = temp;
}

void MoveN(Dice& dice) {
    int temp = dice.Top;
    dice.Top = dice.S;
    dice.S = dice.Bottom;
    dice.Bottom = dice.N;
    dice.N = temp;
}

void MoveS(Dice& dice) {
    int temp = dice.Top;
    dice.Top = dice.N;
    dice.N = dice.Bottom;
    dice.Bottom = dice.S;
    dice.S = temp;
}

void SetDice(Dice& dice) {
    // map�� 0�̸�
    if (map[x][y] == 0) {
        map[x][y] = dice.Bottom;
    }
    // map�� 0�� �ƴϸ�
    else {
        dice.Bottom = map[x][y];
        map[x][y] = 0;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    Dice dice;
    int com;
    bool isPrint;

    for (int i = 0; i < K; i++) {
        cin >> com;
        isPrint = false;
        switch (com) {
        case 1:
            // ��
            if (y + 1 < M) {
                y++;
                MoveE(dice);
                SetDice(dice);
                isPrint = true;
            }
            break;
        case 2:
            // ��
            if (y - 1 >= 0) {
                y--;
                MoveW(dice);
                SetDice(dice);
                isPrint = true;
            }
            break;
        case 3:
            // ��
            if (x - 1 >= 0) {
                x--;
                MoveN(dice);
                SetDice(dice);
                isPrint = true;
            }
            break;
        case 4:
            // ��
            if (x + 1 < N) {
                x++;
                MoveS(dice);
                SetDice(dice);
                isPrint = true;
            }
            break;
        }
        if (isPrint) {
            cout << dice.Top << '\n';
        }
    }
    return 0;
}