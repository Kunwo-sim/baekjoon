#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int dp[100000][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    int ans = arr[0];

    // Á¡È­½Ä
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(arr[i], arr[i] + dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
    return 0;
}