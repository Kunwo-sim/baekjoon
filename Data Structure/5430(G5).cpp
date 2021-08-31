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
        //���� �Ųٷ����� �Ǵ�
        bool reverse = false;
        //������ �ִ��� �Ǵ�
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
            //���ڸ� dq�� int���·� ����
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
            //R�Է��� ������ ���� ��ȯ
            if (com[j] == 'R')
            {
                if (reverse)
                    reverse = false;
                else
                    reverse = true;
            }
            else
            {
                //�����Ұ����� �� error
                if (dq.empty())
                {
                    cout << "error" << endl;
                    iserror = true;
                    break;
                }
                //�������� ���� ��, �������� ���� ��
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
            //������ ���
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
            //������ ���
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