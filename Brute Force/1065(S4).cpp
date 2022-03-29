#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int cnt = 0;
	cin >> n;

	if (n < 100)
	{
		cnt = n;
	}
	else
	{
		cnt += 99;
	}

	for (int i = 100; i <= n; i++)
	{
		int digit1 = i / 100;
		int digit2 = (i % 100) / 10;
		int digit3 = i % 10;

		if ((digit1 - digit2) == (digit2 - digit3))
		{
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}