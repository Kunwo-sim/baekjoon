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
    // v 오름차순 정렬
    sort(v.begin(), v.end());
    // 각각의 차이 만큼 push
    vector<int> s;
    for (int i = 1; i < v.size(); i++) {
        int sub = v[i] - v[i - 1];
        s.push_back(sub);
    }
    // 차이 오름차순 정렬
    sort(s.begin(), s.end());
    // K-1번 만큼 s 뒤에서 pop
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