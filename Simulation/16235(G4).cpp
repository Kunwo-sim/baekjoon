#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
// 나무 정보 : 나이, 생존 여부
struct Tree
{
    int age = 1;
    bool alive = 1;
};

// 나무 정렬할 때 나이 기준 오름차순 정렬
bool cmp(const Tree& a, const Tree& b)
{
    if (a.age < b.age) return true;
    return false;
}

// 맵 정보 : (y, x)에 있는 영양분, 나무
struct Map
{
    int nutrient = 5;
    vector<Tree> tree;
};

int A[10][10];
Map map[10][10];
int N, M, K;

// 나무 나이 오름차순으로 정렬
void SortTree(int x, int y) {
    sort(map[y][x].tree.begin(), map[y][x].tree.end(), cmp);
}

// 봄 : 양분 먹고 나이 증가
void Spring() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 나이순으로 정렬
            SortTree(j, i);
            for (int k = 0; k < map[i][j].tree.size(); k++) {
                // 양분 먹을 수 있으면 성장
                if (map[i][j].nutrient >= map[i][j].tree[k].age) {
                    map[i][j].nutrient -= map[i][j].tree[k].age;
                    map[i][j].tree[k].age++;
                }
                // 아니면 죽음
                else {
                    map[i][j].tree[k].alive = false;
                }
            }
        }
    }
}

// 여름 : 죽은 나무 영양분으로 전환
void Summer() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            while (1) {
                int idx = map[i][j].tree.size() - 1;
                // 나무 죽었으면
                if (idx >= 0 && !map[i][j].tree[idx].alive) {
                    map[i][j].nutrient += map[i][j].tree[idx].age / 2;
                    map[i][j].tree.pop_back();
                }
                else {
                    break;
                }
            }
        }
    }
}


// 가을 : 나무 번식
void Autumn() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < map[i][j].tree.size(); k++) {
                // 나이 5의 배수이면
                if ((map[i][j].tree[k].age % 5) == 0) {
                    for (int q = 0; q < 8; q++) {
                        int nx = j + dx[q];
                        int ny = i + dy[q];
                        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                            // 범위 안이면 나이가 1인 나무 생성
                            map[ny][nx].tree.push_back({ 1, 1 });
                        }
                    }
                }
            }
        }
    }
}

// 겨울 : 양분 추가
void Winter() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j].nutrient += A[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int y, x, z;
        cin >> y >> x >> z;
        y--;
        x--;
        map[y][x].tree.push_back({ z, true });
    }
    // K년 만큼 사계절 반복
    while (K--) {
        Spring();
        Summer();
        Autumn();
        Winter();
    }
    int ans = 0;
    // 살아 있는 나무 개수 세기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < map[i][j].tree.size(); k++) {
                if (map[i][j].tree[k].alive) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}