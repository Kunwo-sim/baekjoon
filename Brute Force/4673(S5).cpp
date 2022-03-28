#include<iostream>
#include<string.h>
using namespace std;

bool isSelfNum[10001];

int CalSelfNumber(int num)
{
	int sum = num;
	while (1)
	{
		if (num == 0)
			break;

		int digit = num % 10;
		sum += digit;
		num /= 10;
	}

	return sum;
}

void CheckSelfNumber(int num)
{
	if (num > 10000 || isSelfNum[num] == false)
		return;

	isSelfNum[num] = false;
	int nextNum = CalSelfNumber(num);
	CheckSelfNumber(CalSelfNumber(num));

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(isSelfNum, true, sizeof(isSelfNum));

	for (int i = 1; i <= 10000; i++)
	{
		if (isSelfNum[i] == false)
			continue;

		cout << i << '\n';
		CheckSelfNumber(CalSelfNumber(i));
	}
	return 0;
}