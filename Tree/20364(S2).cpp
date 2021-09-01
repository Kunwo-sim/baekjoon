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
		//경로를 스택에 넣어줌
		while (temp != 0)
		{
			st.push(temp);
			temp /= 2;
		}
		//스택 꺼내면서 경로확인
		while (!st.empty())
		{
			temp = st.top();
			//경로의 해당 땅을 지나갈 수 없으면
			if (check[temp] == true)
			{
				cout << temp << '\n';
				canreach = false;
				break;
			}
			//지나갈 수 있으면 pop
			else
				st.pop();
		}
		//땅을 가질 수 있는 경우
		if (canreach)
		{
			cout << 0 << '\n';
			check[num] = true;
		}
	}
	return 0;
}