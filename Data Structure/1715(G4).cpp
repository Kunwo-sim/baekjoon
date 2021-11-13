#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // 우선순위 큐(오름차순 정렬)
    priority_queue<int, vector<int>, greater<>> pq;
    int N;
    int sum = 0;
    cin >> N;
    // 입력
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }
    // 두개 꺼내고 다시 넣어줌
    while (1) {
        // 사이즈 1이면 지금까지의 합 출력
        if (pq.size() == 1) {
            cout << sum;
            break;
        }
        int temp1, temp2;
        temp1 = pq.top();
        pq.pop();
        temp2 = pq.top();
        pq.pop();
        int tempsum = temp1 + temp2;
        sum += tempsum;
        pq.push(tempsum);
    }
    return 0;
}