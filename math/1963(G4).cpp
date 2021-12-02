#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;


bool visited[10000];
bool isPrime[10000];
int T;

int CalDigit(int num, int digit) {
    while (digit--)
    {
        num /= 10;
    }
    return num % 10;
}
int bfs(int start, int target) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    visited[start] = true;
    while (!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (num == target) {
            return cnt;
        }
        int temp = 1;
        // 일의 자리부터 바꿔주기
        for (int i = 0; i < 4; i++) {
            // 해당 자리의 수 구하기
            int digit = CalDigit(num, i);
            int t = num - digit * temp;
            for (int j = 0; j <= 9; j++) {
                int next = t + j * temp;
                if (!visited[next] && isPrime[next]) {
                    q.push(make_pair(next, cnt + 1));
                    visited[next] = true;
                }
            }
            temp *= 10;
        }
    }
    return -1;
}

// 에라토스테네스의 체
void SieveofEratosthenes() {
    for (int i = 1; i < 10000; i++) {
        isPrime[i] = true;
    }
    for (int i = 2; i < 100; i++) {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j < 10000; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 1; i < 1000; i++) {
        isPrime[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    SieveofEratosthenes();
    while (T--) {
        int a, b;
        cin >> a >> b;
        int result = bfs(a, b);
        if (result == -1) {
            cout << "Impossible" << '\n';
        }
        else {
            cout << result << '\n';
        }
    }
    return 0;
}