#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

struct lecture
{
    int stime;
    int ttime;
    lecture(int s, int t) : stime(s), ttime(t) {}
};
struct cmpfirst
{
    bool operator()(lecture a, lecture b)
    {
        return a.stime > b.stime;
    }
};
struct cmpsecond
{
    bool operator()(lecture a, lecture b)
    {
        return a.ttime > b.ttime;
    }
};
priority_queue<lecture, vector<lecture>, cmpfirst> pq1;
priority_queue<lecture, vector<lecture>, cmpsecond> pq2;

int main()
{
    int n;
    int s, t;
    int cnt = 0, maxcnt = 0;
    cin >> n;
    //�Է�
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        pq1.push(lecture(s, t));
    }
    while (!pq1.empty())
    {
        int s1, t1;
        s1 = pq1.top().stime;
        t1 = pq1.top().ttime;
        pq1.pop();
        // pq2�� ����ִٸ� �ٷ� Ǫ��
        if (pq2.empty())
        {
            pq2.push(lecture(s1, t1));
            cnt++;
            continue;
        }
        while (1)
        {
            int s2 = pq2.top().stime;
            int t2 = pq2.top().ttime;
            /* pq1.top�� ���� �ð��� pq2.top�� ������ �ð����� ũ�ų� ������ pq2���Ǹ� ������
            pq1�� ������ �� �����Ƿ� pq2�� ��� pop���� */
            if (s1 >= t2)
            {
                pq2.pop();
                cnt--;
            }
            //pq1.top�� ���� �ð��� pq2.top�� ������ �ð����� ������ ���ǽ��� �� �ʿ���.
            else
            {
                pq2.push(lecture(s1, t1));
                cnt++;
                break;
            }
        }
        //���ǽ� ���� ���ؼ� �ִ� ����
        maxcnt = max(cnt, maxcnt);
    }
    cout << maxcnt;
    return 0;
}