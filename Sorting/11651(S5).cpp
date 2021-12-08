#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pos {
    int x;
    int y;
};
bool cmp(const pos& a, const pos& b) {
    if (a.y < b.y)
        return true;
    else if (a.y == b.y && a.x < b.x)
        return true;
    return false;
}

int main() {
    vector<pos> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int xpos, ypos;
        cin >> xpos >> ypos;
        v.push_back({ xpos, ypos });
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].x << ' ' << v[i].y << '\n';
    }
    return 0;
}