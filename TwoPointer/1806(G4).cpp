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
        // ���� ����� ��
        if (left > right || right >= N) {
            break;
        }
        // ���� ũ�� ���� �ּұ��� �����ϰ� �����̱�
        if (sum >= S) {
            int length = right - left + 1;
            minlength = min(minlength, length);
            sum -= arr[left];
            left++;
        }
        // ���� ������ ������ �����̱�
        else {
            right++;
            sum += arr[right];
        }
    }
    // ���� ������ �� ������ 0
    if (minlength == 987654321) {
        minlength = 0;
    }
    cout << minlength;
    return 0;
}