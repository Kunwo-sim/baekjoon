#include <iostream>
#include <cmath>
using namespace std;

int N;
// 소수 판별
bool isPrime(int num) {
    if (num == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 백트래킹
void dfs(int num, int cnt) {
    // 자리수가 N이면 출력
    if (cnt == N) {
        cout << num << '\n';
        return;
    }
    // 1부터 9까지 붙여주면서 next가 소수면 dfs실행
    for (int i = 1; i <= 9; i++) {
        int next = num * 10 + i;
        if (isPrime(next)) {
            dfs(next, cnt + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dfs(0, 0);
    return 0;
}