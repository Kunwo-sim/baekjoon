#include <iostream>
#include <stack>
using namespace std;

// �ش� ���ڰ� ��� �ִ��� ������ �ִ� �迭
int cnt[1000001];
// �ش� ��°�� ���� ������ ngf
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
            // ���� ������ ngf�� stack top idx�� ngf���� ũ�� �� idx�� ngf�� num�� ��. �׷��� pop
            if (cnt[curNum] > ngfCnt)
            {
                ngf[idx] = curNum;
                st.pop();
            }
            // ���� ���ڰ� stack�� top���� ũ�� ������ ����
            else
                break;
        }
        // ngf�� ���ؾ��ϹǷ� �ε����� ���ÿ� ����
        st.push(i);
    }

    // stack�� idx�� ���������� ngf �� ã�� ��, �迭�� -1 �־���
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