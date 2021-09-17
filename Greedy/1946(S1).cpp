#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        vector<pair<int, int>> v;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        sort(v.begin(), v.end());
        int cnt = 1;
        int max = v[0].second;
        for (int i = 1; i < n; i++) {
            if (v[i].second < max) {
                cnt++;
                max = v[i].second;
            }
        }
        cout << cnt << '\n';
        t--;
    }
    return 0;
}