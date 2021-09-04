#include<iostream>
using namespace std;

int dp[14];
int main()
{
	int t;
	cin >> t;
	dp[0] = 1;
	for (int i = 0; i < 10; i++)
	{
		int cur = dp[i];
		dp[i + 1] += cur;
		dp[i + 2] += cur;
		dp[i + 3] += cur;
	}
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}