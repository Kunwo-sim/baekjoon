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
            if (v[i] == v[i + 1].substr(0, v[i].length())) {
                coherent = false;
                break;
            }
        }
        // 일관성이 있으면
        if (coherent) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}