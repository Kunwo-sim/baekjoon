#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int square[1000][1000];
int dp[1000][1000];
int n, m;
int main()
{
	int maxlength = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			char temp = s[j];
			square[i][j] = temp - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i][j] = square[i][j];
			int size = dp[i][j];
			if (square[i][j] == 1 && i != 0 && j != 0)
			{
				size = min(dp[i - 1][j], dp[i][j - 1]);
				size = min(dp[i - 1][j - 1], size);
				size++;
				dp[i][j] = size;
			}
			maxlength = max(size, maxlength);
		}
	}
	cout << maxlength * maxlength;
	return 0;
}