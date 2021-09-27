#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[10001];
int main() {
	int t;
	cin >> t;
	while (t > 0) {
		// �Է�
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int coin;
			cin >> coin;
			v.push_back(coin);
		}
		int M;
		cin >> M;
		// �ʱ�ȭ
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		// ��ȭ�� ���
		for (int i = 0; i < v.size(); i++) {
			for (int j = v[i]; j <= M; j++) {
				dp[j] = dp[j] + dp[j - v[i]];
			}
		}
		cout << dp[M] << '\n';
		t--;
	}
	return 0;
}