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
    //입력
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
        // pq2가 비어있다면 바로 푸쉬
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
            /* pq1.top의 시작 시간이 pq2.top의 끝나는 시간보다 크거나 같으면 pq2강의를 끝내고
            pq1을 시작할 수 있으므로 pq2를 계속 pop해줌 */
            if (s1 >= t2)
            {
                pq2.pop();
                cnt--;
            }
            //pq1.top의 시작 시간이 pq2.top의 끝나는 시간보다 작으면 강의실이 더 필요함.
            else
            {
                pq2.push(lecture(s1, t1));
                cnt++;
                break;
            }
        }
        //강의실 개수 비교해서 최댓값 갱신
        maxcnt = max(cnt, maxcnt);
    }
    cout << maxcnt;
    return 0;
}