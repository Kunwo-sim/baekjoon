#include <iostream>
#include <cmath>
using namespace std;

int N;
// �Ҽ� �Ǻ�
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

// ��Ʈ��ŷ
void dfs(int num, int cnt) {
    // �ڸ����� N�̸� ���
    if (cnt == N) {
        cout << num << '\n';
        return;
    }
    // 1���� 9���� �ٿ��ָ鼭 next�� �Ҽ��� dfs����
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