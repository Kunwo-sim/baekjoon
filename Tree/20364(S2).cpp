#include<iostream>
#include<stack>
using namespace std;

bool check[1048577]; // 2^20;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < Q; i++)
	{
		int num;
		cin >> num;
		int temp = num;
		bool canreach = true;
		stack<int> st;
		//��θ� ���ÿ� �־���
		while (temp != 0)
		{
			st.push(temp);
			temp /= 2;
		}
		//���� �����鼭 ���Ȯ��
		while (!st.empty())
		{
			temp = st.top();
			//����� �ش� ���� ������ �� ������
			if (check[temp] == true)
			{
				cout << temp << '\n';
				canreach = false;
				break;
			}
			//������ �� ������ pop
			else
				st.pop();
		}
		//���� ���� �� �ִ� ���
		if (canreach)
		{
			cout << 0 << '\n';
			check[num] = true;
		}
	}
	return 0;
}