#include <iostream>
#include <vector>
using namespace std;

struct info
{
    // ��
    int value;
    // ��������� ���� ���� �κ� ������ ����
    int LIS;
    // �θ�
    int parent;
};
vector<info> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // �Է�
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back({ num, 1, -1 });
    }
    // ���� �� �κ� ������ ������ idx
    int idx = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            // ���� �� �۰�, LIS ������ �ʿ䰡 ������
            if (v[j].value < v[i].value && v[j].LIS + 1 > v[i].LIS) {
                // LIS ����
                v[i].LIS = v[j].LIS + 1;
                v[i].parent = j;
                // idx ����
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
        // �θ� �� �̻� ������ ���
        if (v[idx].parent == -1) {
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i] << ' ';
            }
            break;
        }
        // �θ� ������ ��� �־��ֱ�
        else {
            idx = v[idx].parent;
        }
    }
    return 0;
}