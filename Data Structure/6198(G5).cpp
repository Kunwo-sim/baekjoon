#include<iostream>
#include<stack>
using namespace std;

int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	long long answer = 0;
	stack<int> st;
	for (int i = 0; i < N; i++)
	{
		int height;
		cin >> height;
		while (1) {
			if (st.empty())
			{
				st.push(height);
				break;
			}
			else if (st.top() > height)
			{
				answer += st.size();
				st.push(height);
				break;
			}
			else {
				st.pop();
			}
		}
	}
	cout << answer;
	return 0;
}