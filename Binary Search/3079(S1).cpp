#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // end 값에 유의
    long long start = 1, end = 1000000000000000000;
    long long mintime = end;
    while (end >= start)
    {
        long long mid = (start + end) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            // mid 시간에 통과할 수 있는 사람 계산
            sum += mid / arr[i];
            if (sum >= m)
                break;
        }
        // 통과할 수 있는 사람 수가 조건보다 많으면
        if (sum >= m)
        {
            mintime = min(mintime, mid);
            end = mid - 1;
        }
        // 통과할 수 있는 사람 수가 조건보다 적으면
        else
        {
            start = mid + 1;
        }
    }
    cout << mintime;
    return 0;
}