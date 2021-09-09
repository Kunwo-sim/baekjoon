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

	//������ �Ȱ����� ���
	if (issame)
	{
		cout << color;
	}
	else
	{
		// ������ �ٸ��� 4����
		int nsize = size / 2;
		cout << "(";
		//�»�
		fun(sx, sy, nsize);
		//���
		fun(sx + nsize, sy, nsize);
		//����
		fun(sx, sy + nsize, nsize);
		//����
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
			//map�� int �������� ����
			map[i][j] = s[j - 1] - '0';
		}
	}
	fun(1, 1, N);
	return 0;
}