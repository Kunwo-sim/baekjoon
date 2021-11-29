#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// ��Ŭ���� ȣ����
int FindGcd(int a, int b) {
    if (b % a == 0) {
        return a;
    }
    else {
        return FindGcd(b % a, a);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // �ִ�����, �ּҰ����
    int gcd, lcm;
    cin >> gcd >> lcm;
    int num = lcm / gcd;
    int minSum = 987654321;
    int minA = 0, minB = 0;
    // num�� ��� ���ϱ�
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            int a = i;
            int b = num / i;
            // a, b�� ���μ��� ��
            if (FindGcd(a, b) == 1) {
                // ���� �� �۴ٸ� ����
                if (a + b < minSum) {
                    minSum = a + b;
                    minA = a;
                    minB = b;
                }
            }
        }
    }
    cout << minA * gcd << ' ' << minB * gcd;
    return 0;
}