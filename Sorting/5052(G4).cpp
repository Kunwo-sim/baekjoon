#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> v;
        for (int i = 0; i < N; i++)
        {
            string str;
            cin >> str;
            v.push_back(str);
        }
        sort(v.begin(), v.end());
        bool coherent = true;
        for (int i = 0; i < v.size() - 1; i++)
        {
            coherent = false;
            if (v[i].size() > v[i + 1].size()) {
                continue;
            }
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] != v[i + 1][j]) {
                    // �ٸ��� �ϰ����� ����
                    coherent = true;
                    break;
                }
            }
            // ��� ������ (�ϰ����� ������)
            if (!coherent) {
                cout << "NO" << '\n';
                break;
            }
        }
        // ���������� �ϰ����� ������
        if (coherent) {
            cout << "YES" << '\n';
        }
    }
    return 0;
}