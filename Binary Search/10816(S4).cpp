#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v;
	int n, m;

	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << ' ';
	}

	return 0;
}