#include <iostream>
using namespace std;

int E, S, M;
int Ecnt, Scnt, Mcnt, cnt;
int main() {
    cin >> E >> S >> M;
    while (1) {
        if (E == Ecnt && S == Scnt && M == Mcnt) {
            cout << cnt;
            break;
        }
        Ecnt++;
        Scnt++;
        Mcnt++;
        cnt++;
        if (Ecnt >= 16)
            Ecnt = 1;
        if (Scnt >= 29)
            Scnt = 1;
        if (Mcnt >= 20)
            Mcnt = 1;
    }
    return 0;
}