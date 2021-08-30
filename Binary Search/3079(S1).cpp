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
    // end ���� ����
    long long start = 1, end = 1000000000000000000;
    long long mintime = end;
    while (end >= start)
    {
        long long mid = (start + end) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            // mid �ð��� ����� �� �ִ� ��� ���
            sum += mid / arr[i];
            if (sum >= m)
                break;
        }
        // ����� �� �ִ� ��� ���� ���Ǻ��� ������
        if (sum >= m)
        {
            mintime = min(mintime, mid);
            end = mid - 1;
        }
        // ����� �� �ִ� ��� ���� ���Ǻ��� ������
        else
        {
            start = mid + 1;
        }
    }
    cout << mintime;
    return 0;
}