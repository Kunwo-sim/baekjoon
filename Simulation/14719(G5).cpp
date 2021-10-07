#include <iostream>
using namespace std;

int map[500][500];

int main()
{
    // �Է�, 0 : �� ��, 1 : ��ֹ�
    int H, W;
    cin >> H >> W;
    int height;
    for (int i = 0; i < W; i++) {
        cin >> height;
        for (int j = H - height; j < H; j++) {
            map[j][i] = 1;
        }
    }

    // �� ������ ���鼭 �˻�
    int raindrop = 0;
    for (int i = 0; i < H; i++) {
        int start = -1;
        for (int j = 0; j < W; j++) {
            // ��ֹ��� ��
            if (map[i][j] == 1) {
                if (start != -1) {
                    // ���� ��ġ�� start ���� ��ŭ ������ ����.
                    raindrop += j - start - 1;
                }
                // start ����
                start = j;
            }
        }
    }
    cout << raindrop;
    return 0;
}