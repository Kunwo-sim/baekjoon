#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[101][100001];
int w[101];
int v[101];
int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            //물건을 넣을 수 있는 경우
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            //물건을 넣을 수 없는 경우
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
    return 0;
}
