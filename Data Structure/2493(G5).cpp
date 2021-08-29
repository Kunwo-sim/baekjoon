#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int tower[500001];
int receive[500001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tower[i];
    }
    //≥Ù¿Ã, ¿Œµ¶Ω∫
    stack<pair<int, int>> st;
    int idx = n;
    for (int i = n; i > 0; i--)
    {
        if (!st.empty())
        {
            while (st.top().first < tower[i])
            {
                receive[st.top().second] = i;
                st.pop();
                if (st.empty())
                    break;
            }
        }
        st.push(make_pair(tower[i], i));
    }
    for (int i = 1; i <= n; i++)
    {
        cout << receive[i] << ' ';
    }
    return 0;
}
