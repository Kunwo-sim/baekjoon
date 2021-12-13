#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];
int LIS[1000];
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        LIS[i] = 1;
    }
    int result = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (A[i] > A[j]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
                result = max(LIS[i], result);
            }
        }
    }
    cout << result;
    return 0;
}