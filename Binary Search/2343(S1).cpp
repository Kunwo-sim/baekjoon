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
	int length;

	int low = 0;
	int mid = 0;
	int high = 2000000000;
	int result = 0;
	int diskCnt = 0;
	long long lengthSum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> length;
		v.push_back(length);
	}

	while (1)
	{
		if (low > high)
			break;

		mid = (low + high) / 2;
		diskCnt = 1;
		lengthSum = 0;
		bool isEnough = true;

		for (int diskLength : v)
		{
			lengthSum += diskLength;

			if (lengthSum > mid)
			{
				// 디스크 개수 부족
				if (diskCnt >= M || diskLength > mid)
				{
					isEnough = false;
					break;
				}

				diskCnt += 1;
				lengthSum = diskLength;
			}
		}

		if (isEnough)
		{
			high = mid - 1;
			result = mid;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << result;
	return 0;
}