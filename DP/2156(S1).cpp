#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[10000];
// dp[�ε���][��� �������� ���̴���]
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
		// �̹��� �� ���� ��
		dp[i][0] = max(max(dp[i - 1][1], dp[i - 1][2]), dp[i - 1][0]);
		// �� �� �� ���ð�, �̹��� ���� ��
		dp[i][1] = dp[i - 1][0] + arr[i];
		// �� �� ���ð�, �̹� �͵� ���� ��
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	maxsum = max(dp[n - 1][0], dp[n - 1][1]);
	maxsum = max(maxsum, dp[n - 1][2]);
	cout << maxsum;
	return 0;
}