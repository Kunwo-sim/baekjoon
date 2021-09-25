#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[201];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int n;
    cin >> n;
    int LIS = 0;
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // LIS 구하기
    for (int i = 1; i < v.size(); i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                temp = max(dp[j], temp);
            }
        }
        dp[i] = temp + 1;
        LIS = max(LIS, dp[i]);
    }

    cout << n - LIS << endl;
    return 0;
}