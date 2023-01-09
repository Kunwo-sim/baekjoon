#include <iostream>
#include <stack>
using namespace std;

// 해당 숫자가 몇개나 있는지 가지고 있는 배열
int cnt[1000001];
// 해당 번째로 들어온 숫자의 ngf
int ngf[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<int> st;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        ngf[i] = num;
        cnt[num]++;
    }

    for (int i = 0; i < N; i++)
    {
        int curNum = ngf[i];

        while (!st.empty())
        {
            int idx = st.top();
            int ngfCnt = cnt[ngf[idx]];
            // 현재 숫자의 ngf가 stack top idx의 ngf보다 크면 그 idx의 ngf는 num이 됨. 그런뒤 pop
            if (cnt[curNum] > ngfCnt)
            {
                ngf[idx] = curNum;
                st.pop();
            }
            // 현재 숫자가 stack의 top보다 크지 않으면 멈춤
            else
                break;
        }
        // ngf를 구해야하므로 인덱스를 스택에 넣음
        st.push(i);
    }

    // stack에 idx가 남아있으면 ngf 못 찾은 것, 배열에 -1 넣어줌
    while (!st.empty())
    {
        int failIdx = st.top();
        st.pop();

        ngf[failIdx] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        cout << ngf[i] << ' ';
    }

    return 0;
}