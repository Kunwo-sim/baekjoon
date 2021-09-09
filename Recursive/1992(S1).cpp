#include<iostream>
#include<string>
using namespace std;

int map[65][65];
int N;

void fun(int sx, int sy, int size)
{
	int color = map[sy][sx];
	bool issame = true;
	for (int i = sy; i < sy + size; i++)
	{
		for (int j = sx; j < sx + size; j++)
		{
			if (color != map[i][j])
			{
				issame = false;
				break;
			}
		}
		if (!issame)
			break;
	}

	//색깔이 똑같으면 출력
	if (issame)
	{
		cout << color;
	}
	else
	{
		// 색깔이 다르면 4분할
		int nsize = size / 2;
		cout << "(";
		//좌상
		fun(sx, sy, nsize);
		//우상
		fun(sx + nsize, sy, nsize);
		//좌하
		fun(sx, sy + nsize, nsize);
		//우하
		fun(sx + nsize, sy + nsize, nsize);
		cout << ")";
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= s.size(); j++)
		{
			//map에 int 형식으로 저장
			map[i][j] = s[j - 1] - '0';
		}
	}
	fun(1, 1, N);
	return 0;
}