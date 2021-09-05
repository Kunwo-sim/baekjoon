#include<iostream>
using namespace std;

long long dp[101];

int main()
{
	int t;
	int num;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> num;
		cout << dp[num] << '\n';
	}
	return 0;
}