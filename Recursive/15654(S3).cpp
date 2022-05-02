#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> v;
vector<int> result;
bool isSelected[8];

void Print()
{
	for (int num : result)
	{
		cout << num << ' ';
	}
	cout << '\n';
}

void Select(int cnt)
{
	if (cnt == M)
	{
		Print();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (isSelected[i])
			continue;

		isSelected[i] = true;
		result.push_back(v[i]);
		Select(cnt + 1);
		isSelected[i] = false;
		result.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	Select(0);

	return 0;
}