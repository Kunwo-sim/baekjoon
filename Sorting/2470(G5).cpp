#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    vector<int> target;
    // 입력
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        v.push_back(size);
    }
    // 정렬
    sort(v.begin(), v.end());
    int left = 0;
    int right = v.size() - 1;
    int minsum = 2087654321;
    // 두포인터
    while (right > left) {
        int sum = v[left] + v[right];
        if (abs(sum) < minsum) {
            minsum = abs(sum);
            target.clear();
            target.push_back(v[left]);
            target.push_back(v[right]);
        }
        // 합이 양수인 경우
        if (sum > 0) {
            // 0에 가까워지려면 합 감소시켜야함
            right--;
        }
        // 합이 음수인 경우
        else {
            // 0에 가까워지려면 합 증가시켜야함
            left++;
        }
    }

    cout << target[0] << ' ' << target[1];
    return 0;
}#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    vector<int> target;
    // 입력
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        v.push_back(size);
    }
    // 정렬
    sort(v.begin(), v.end());
    int left = 0;
    int right = v.size() - 1;
    int minsum = 2087654321;
    // 두포인터
    while (right > left) {
        int sum = v[left] + v[right];
        if (abs(sum) < minsum) {
            minsum = abs(sum);
            target.clear();
            target.push_back(v[left]);
            target.push_back(v[right]);
        }
        // 합이 양수인 경우
        if (sum > 0) {
            // 0에 가까워지려면 합 감소시켜야함
            right--;
        }
        // 합이 음수인 경우
        else {
            // 0에 가까워지려면 합 증가시켜야함
            left++;
        }
    }

    cout << target[0] << ' ' << target[1];
    return 0;
}