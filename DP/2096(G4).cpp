#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int a, b, c;
    cin >> a >> b >> c;
    // 지금까지의 최대, 최소
    int aMax = a, bMax = b, cMax = c;
    int aMin = a, bMin = b, cMin = c;
    // 다음 최대, 최소
    int aMaxNext, bMaxNext, cMaxNext;
    int aMinNext, bMinNext, cMinNext;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        // 최댓값 갱신
        aMaxNext = max(aMax, bMax) + a;
        bMaxNext = max(max(aMax, bMax), cMax) + b;
        cMaxNext = max(bMax, cMax) + c;
        aMax = aMaxNext;
        bMax = bMaxNext;
        cMax = cMaxNext;
        // 최솟값 갱신
        aMinNext = min(aMin, bMin) + a;
        bMinNext = min(min(aMin, bMin), cMin) + b;
        cMinNext = min(bMin, cMin) + c;
        aMin = aMinNext;
        bMin = bMinNext;
        cMin = cMinNext;
    }
    int Max = max(max(aMax, bMax), cMax);
    int Min = min(min(aMin, bMin), cMin);
    cout << Max << ' ' << Min;
    return 0;
}