#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// 유클리드 호제법
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
    // 최대공약수, 최소공배수
    int gcd, lcm;
    cin >> gcd >> lcm;
    int num = lcm / gcd;
    int minSum = 987654321;
    int minA = 0, minB = 0;
    // num의 약수 구하기
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            int a = i;
            int b = num / i;
            // a, b가 서로소일 때
            if (FindGcd(a, b) == 1) {
                // 합이 더 작다면 갱신
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