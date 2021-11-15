#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int sum[26];
int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // �Է�
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int temp = 1;
        // ���ڸ� ���� ����ġ ���
        for (int j = s.length() - 1; j >= 0; j--) {
            int idx = s.at(j) - 65;
            sum[idx] += temp;
            temp *= 10;
        }
    }
    vector<int> v;
    // ���ĺ� �� vector�� Ǫ��
    for (int i = 0; i < 26; i++) {
        if (sum[i] != 0) {
            v.push_back(sum[i]);
        }
    }
    // �������� ����
    sort(v.begin(), v.end());
    int mul = 9;
    int result = 0;
    // ������ 9, 8, 7... �����ֱ�
    while (!v.empty())
    {
        result += v.back() * mul;
        mul--;
        v.pop_back();
    }
    cout << result;
    return 0;
}