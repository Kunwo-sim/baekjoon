#include <iostream>
using namespace std;

int map[500][500];

int main()
{
    // 입력, 0 : 빈 곳, 1 : 장애물
    int H, W;
    cin >> H >> W;
    int height;
    for (int i = 0; i < W; i++) {
        cin >> height;
        for (int j = H - height; j < H; j++) {
            map[j][i] = 1;
        }
    }

    // 전 영역을 돌면서 검사
    int raindrop = 0;
    for (int i = 0; i < H; i++) {
        int start = -1;
        for (int j = 0; j < W; j++) {
            // 장애물일 때
            if (map[i][j] == 1) {
                if (start != -1) {
                    // 현재 위치와 start 사이 만큼 빗물이 찬다.
                    raindrop += j - start - 1;
                }
                // start 갱신
                start = j;
            }
        }
    }
    cout << raindrop;
    return 0;
}