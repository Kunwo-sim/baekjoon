#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
// ���� ���� : ����, ���� ����
struct Tree
{
    int age = 1;
    bool alive = 1;
};

// ���� ������ �� ���� ���� �������� ����
bool cmp(const Tree& a, const Tree& b)
{
    if (a.age < b.age) return true;
    return false;
}

// �� ���� : (y, x)�� �ִ� �����, ����
struct Map
{
    int nutrient = 5;
    vector<Tree> tree;
};

int A[10][10];
Map map[10][10];
int N, M, K;

// ���� ���� ������������ ����
void SortTree(int x, int y) {
    sort(map[y][x].tree.begin(), map[y][x].tree.end(), cmp);
}

// �� : ��� �԰� ���� ����
void Spring() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // ���̼����� ����
            SortTree(j, i);
            for (int k = 0; k < map[i][j].tree.size(); k++) {
                // ��� ���� �� ������ ����
                if (map[i][j].nutrient >= map[i][j].tree[k].age) {
                    map[i][j].nutrient -= map[i][j].tree[k].age;
                    map[i][j].tree[k].age++;
                }
                // �ƴϸ� ����
                else {
                    map[i][j].tree[k].alive = false;
                }
            }
        }
    }
}

// ���� : ���� ���� ��������� ��ȯ
void Summer() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            while (1) {
                int idx = map[i][j].tree.size() - 1;
                // ���� �׾�����
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


// ���� : ���� ����
void Autumn() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < map[i][j].tree.size(); k++) {
                // ���� 5�� ����̸�
                if ((map[i][j].tree[k].age % 5) == 0) {
                    for (int q = 0; q < 8; q++) {
                        int nx = j + dx[q];
                        int ny = i + dy[q];
                        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                            // ���� ���̸� ���̰� 1�� ���� ����
                            map[ny][nx].tree.push_back({ 1, 1 });
                        }
                    }
                }
            }
        }
    }
}

// �ܿ� : ��� �߰�
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
    // K�� ��ŭ ����� �ݺ�
    while (K--) {
        Spring();
        Summer();
        Autumn();
        Winter();
    }
    int ans = 0;
    // ��� �ִ� ���� ���� ����
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