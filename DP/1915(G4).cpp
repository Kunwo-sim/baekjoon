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
				// 왼쪽과 위쪽 비교
				size = min(dp[i - 1][j], dp[i][j - 1]);
				// 대각선 왼쪽위 비교
				size = min(dp[i - 1][j - 1], size);
				size++;
				dp[i][j] = size;
			}
			// 최댓값 비교
			maxlength = max(size, maxlength);
		}
	}
	// 넓이
	cout << maxlength * maxlength;
	return 0;
}