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
    // �Է�
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        v.push_back(size);
    }
    // ����
    sort(v.begin(), v.end());
    int left = 0;
    int right = v.size() - 1;
    int minsum = 2087654321;
    // ��������
    while (right > left) {
        int sum = v[left] + v[right];
        if (abs(sum) < minsum) {
            minsum = abs(sum);
            target.clear();
            target.push_back(v[left]);
            target.push_back(v[right]);
        }
        // ���� ����� ���
        if (sum > 0) {
            // 0�� ����������� �� ���ҽ��Ѿ���
            right--;
        }
        // ���� ������ ���
        else {
            // 0�� ����������� �� �������Ѿ���
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
    // �Է�
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        v.push_back(size);
    }
    // ����
    sort(v.begin(), v.end());
    int left = 0;
    int right = v.size() - 1;
    int minsum = 2087654321;
    // ��������
    while (right > left) {
        int sum = v[left] + v[right];
        if (abs(sum) < minsum) {
            minsum = abs(sum);
            target.clear();
            target.push_back(v[left]);
            target.push_back(v[right]);
        }
        // ���� ����� ���
        if (sum > 0) {
            // 0�� ����������� �� ���ҽ��Ѿ���
            right--;
        }
        // ���� ������ ���
        else {
            // 0�� ����������� �� �������Ѿ���
            left++;
        }
    }

    cout << target[0] << ' ' << target[1];
    return 0;
}