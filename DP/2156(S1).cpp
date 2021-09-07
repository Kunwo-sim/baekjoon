#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[10000];
// dp[인덱스][몇번 연속으로 마셨는지]
int dp[10000][3];
int maxsum;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dp[0][1] = arr[0];
	for (int i = 1; i < n; i++)
	{
		// 이번에 안 마실 때
		dp[i][0] = max(max(dp[i - 1][1], dp[i - 1][2]), dp[i - 1][0]);
		// 전 꺼 안 마시고, 이번에 마실 때
		dp[i][1] = dp[i - 1][0] + arr[i];
		// 전 꺼 마시고, 이번 것도 마실 때
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	maxsum = max(dp[n - 1][0], dp[n - 1][1]);
	maxsum = max(maxsum, dp[n - 1][2]);
	cout << maxsum;
	return 0;
}