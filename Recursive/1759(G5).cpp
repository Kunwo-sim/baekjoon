#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<char> v;
vector<char> password;
int length, num;
int vowel, conso;

void printpw(int start, int cnt)
{
	// 출력
	if (cnt == length)
	{
		vowel = 0;
		conso = 0;
		for (int i = 0; i < password.size(); i++)
		{
			if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
				vowel++;
			else
				conso++;
		}
		if (vowel >= 1 && conso >= 2)
		{
			for (int i = 0; i < password.size(); i++)
			{
				cout << password[i];
			}
			cout << '\n';
		}
		return;
	}

	// 루프돌면서 printpw에 넣어주기
	for (int i = start; i < v.size(); i++)
	{
		password.push_back(v[i]);
		printpw(i + 1, cnt + 1);
		password.pop_back();
	}
	return;
}

int main()
{
	cin >> length >> num;
	for (int i = 0; i < num; i++)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	printpw(0, 0);
	return 0;
}