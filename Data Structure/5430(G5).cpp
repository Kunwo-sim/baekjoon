#include<iostream>
#include<deque>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        //현재 거꾸로인지 판단
        bool reverse = false;
        //에러가 있는지 판단
        bool iserror = false;
        string com;
        cin >> com;
        int leng;
        cin >> leng;
        string s;
        cin >> s;
        deque<int> dq;
        string temp;
        for (int j = 0; j < s.size(); j++)
        {
            //숫자만 dq에 int형태로 전달
            if (s[j] == '[')
                continue;
            else if (s[j] >= '0' && s[j] <= '9')
                temp += s[j];
            else if (s[j] == ',' || s[j] == ']')
            {
                if (!temp.empty())
                {
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }
        for (int j = 0; j < com.size(); j++)
        {
            //R입력을 받으면 방향 전환
            if (com[j] == 'R')
            {
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else
            {
                //삭제불가능할 때 error
                if (dq.empty())
                {
                    cout << "error" << endl;
                    iserror = true;
                    break;
                }
                //정방향일 때는 앞, 역방향일 때는 뒤
                if (reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        if (iserror)
            continue;
        else
        {
            //역방향 출력
            if (reverse)
            {
                cout << "[";
                while (!dq.empty())
                {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty())
                        cout << ",";
                }
                cout << "]";
            }
            //정방향 출력
            else
            {
                cout << "[";
                while (!dq.empty())
                {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty())
                        cout << ",";
                }
                cout << "]";
            }
        }
        cout << '\n';
    }
    return 0;
}