#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int K;
    cin >> N >> K;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    // v �������� ����
    sort(v.begin(), v.end());
    // ������ ���� ��ŭ push
    vector<int> s;
    for (int i = 1; i < v.size(); i++) {
        int sub = v[i] - v[i - 1];
        s.push_back(sub);
    }
    // ���� �������� ����
    sort(s.begin(), s.end());
    // K-1�� ��ŭ s �ڿ��� pop
    while (--K) {
        if (s.empty())
            break;
        s.pop_back();
    }
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i];
    }
    cout << sum;
    return 0;
}