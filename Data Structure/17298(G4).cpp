#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<int> st;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = num;
        while (1) {
            // ������ ������� �ٷ� push
            if (st.empty()) {
                st.push(i);
                break;
            }
            // ������ ���� �ʾ����� ������ Top�� ��
            int idx = st.top();
            // num�� �� Ŭ ��쿡�� index�� �ش��ϴ� ���ҿ� num�� �־��ְ� Pop
            if (num > arr[idx]) {
                arr[idx] = num;
                st.pop();
            }
            // num�� �۰ų� ������ ���ÿ� push�ϰ� ���� ���� Ȯ��
            else {
                st.push(i);
                break;
            }
        }
    }
    // ���ÿ� ���� �ִ� index�鿡 �ش��ϴ� ���Ҵ� �� ū ���� �����Ƿ� -1�� �־���
    while (!st.empty()) {
        int idx = st.top();
        arr[idx] = -1;
        st.pop();
    }
    // ��ū���� ���
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}