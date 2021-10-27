#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int main()
{
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int right = 0;
    int left = 0;
    int sum = arr[0];
    int minlength = 987654321;
    while (1) {
        // 범위 벗어나면 끝
        if (left > right || right >= N) {
            break;
        }
        // 합이 크면 왼쪽 최소길이 갱신하고 움직이기
        if (sum >= S) {
            int length = right - left + 1;
            minlength = min(minlength, length);
            sum -= arr[left];
            left++;
        }
        // 합이 작으면 오른쪽 움직이기
        else {
            right++;
            sum += arr[right];
        }
    }
    // 조건 만족할 수 없으면 0
    if (minlength == 987654321) {
        minlength = 0;
    }
    cout << minlength;
    return 0;
}