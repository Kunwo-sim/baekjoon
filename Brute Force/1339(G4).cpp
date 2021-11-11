#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string strarr[10];
int Value[26];
bool check[26];
int ValueCheck[11]; // 0 ~ 10까지
int total;
int N, maxsum;

// strarr 배열에 있는 수들의 합 구하기
void CalSum() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int temp = 1;
        for (int j = strarr[i].length() - 1; j >= 0; j--) {
            int idx = strarr[i].at(j) - 65;
            sum += temp * Value[idx];
            temp *= 10;
        }
    }
    // 갱신
    maxsum = max(maxsum, sum);
}

// 백트래킹
void dfs(int idx, int cnt) {
    // 알파벳에 값 모두 할당했으면 계산
    if (cnt == total) {
        CalSum();
        return;
    }
    // 없는 알파벳은 건너 뜀
    while (1) {
        if (check[idx]) {
            break;
        }
        idx++;
    }
    // 값은 0 ~ 10까지
    for (int i = 0; i < 10; i++) {
        if (ValueCheck[i]) {
            continue;
        }
        Value[idx] = i;
        ValueCheck[i] = true;
        dfs(idx + 1, cnt + 1);
        ValueCheck[i] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        strarr[i] = s;
        for (int j = 0; j < s.length(); j++) {
            int idx = s.at(j) - 65;
            check[idx] = true;
        }
    }
    // 알파벳 몇개 인지 세기
    for (int i = 0; i < 26; i++) {
        if (check[i]) {
            total++;
        }
    }
    dfs(0, 0);
    cout << maxsum;
    return 0;
}