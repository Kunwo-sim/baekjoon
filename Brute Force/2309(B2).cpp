#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;
vector<int> result;
int heigth;
int heigthSum = 0;

void Solution()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int sum = heigthSum - v[i] - v[j];

			if (sum == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j)
						continue;

					result.push_back(v[k]);
				}
				return;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> heigth;
		heigthSum += heigth;
		v.push_back(heigth);
	}

	Solution();

	sort(result.begin(), result.end());

	for (int num : result)
	{
		cout << num << '\n';
	}

	return 0;
}