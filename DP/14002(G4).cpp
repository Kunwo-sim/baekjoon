#include <iostream>
#include <vector>
using namespace std;

struct info
{
    // 값
    int value;
    // 여기까지의 최장 증가 부분 수열의 길이
    int LIS;
    // 부모
    int parent;
};
vector<info> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back({ num, 1, -1 });
    }
    // 제일 긴 부분 수열의 마지막 idx
    int idx = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            // 값이 더 작고, LIS 갱신할 필요가 있으면
            if (v[j].value < v[i].value && v[j].LIS + 1 > v[i].LIS) {
                // LIS 갱신
                v[i].LIS = v[j].LIS + 1;
                v[i].parent = j;
                // idx 갱신
                if (v[i].LIS > v[idx].LIS) {
                    idx = i;
                }
            }
        }
    }
    vector<int> ans;
    cout << v[idx].LIS << endl;
    while (1) {
        ans.push_back(v[idx].value);
        // 부모가 더 이상 없으면 출력
        if (v[idx].parent == -1) {
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i] << ' ';
            }
            break;
        }
        // 부모 있으면 계속 넣어주기
        else {
            idx = v[idx].parent;
        }
    }
    return 0;
}