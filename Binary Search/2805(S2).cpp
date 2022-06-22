#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> v;
	int height;

	int low = 0;
	int mid = 0;
	int high = 0;
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> height;
		v.push_back(height);

		if (height > high)
		{
			high = height;
		}
	}

	while (1)
	{
		if (low > high)
			break;

		mid = (low + high) / 2;
		long long sum = 0;

		for (int treeHeight : v)
		{
			int cutHeight = treeHeight - mid;

			if (cutHeight > 0)
			{
				sum += cutHeight;
			}
		}

		// 목표치 달성
		if (sum >= M)
		{
			result = mid;
			low = mid + 1;
		}
		// 목표치 미달성
		else
		{
			high = mid - 1;
		}
	}

	cout << result;
	return 0;
}