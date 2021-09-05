#include<iostream>
using namespace std;

bool color;
int bluesum;
int whitesum;
int n;
bool map[129][129];

void fun(int sx, int sy, int size)
{
	bool check = true;
	// 색깔 점검
	if (map[sy][sx] == 1)
		color = 1;
	else
		color = 0;
	// 범위에 다른 색깔 있는지 확인
	for (int i = sy; i < sy + size; i++)
	{
		for (int j = sx; j < sx + size; j++)
		{
			if (map[i][j] != color)
			{
				check = false;
				break;
			}
		}
		if (!check)
			break;
	}
	// 다른 색깔 없으면
	if (check)
	{
		if (color)
			bluesum++;
		else
			whitesum++;
	}
	// 다른 색깔 있으면
	else
	{
		int nsize = size / 2;
		fun(sx, sy, nsize);
		fun(sx, sy + nsize, nsize);
		fun(sx + nsize, sy, nsize);
		fun(sx + nsize, sy + nsize, nsize);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}
	fun(1, 1, n);
	cout << whitesum << endl << bluesum;
	return 0;
}