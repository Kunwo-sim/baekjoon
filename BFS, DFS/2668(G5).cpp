#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int graph[101];
bool visited[101];
bool check[101];
vector<int> v;
int cnt;
int maxcnt;

void dfs(int start, int node) {
	visited[node] = true;
	int next = graph[node];
	cnt++;
	v.push_back(node);
	// ���� �������� ���ƿ��� �ߺ� �˻�
	if (next == start) {
		bool overlap = false;
		// �ߺ� �˻�
		for (int i = 0; i < v.size(); i++) {
			if (check[v[i]] == true) {
				overlap = true;
				break;
			}
		}
		// �ٸ� �κа� �ߺ����� ������ check ���ֱ�
		if (!overlap) {
			for (int i = 0; i < v.size(); i++) {
				check[v[i]] = true;
			}
			maxcnt += cnt;
		}
	}
	// �ٸ� �湮�� ���� ���� ��쿡�� return
	else if (visited[next])
		return;
	// �湮���� �ʾ����� dfs ��� ȣ��
	else {
		dfs(start, next);
	}
}
int main() {
	// �Է�
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> graph[i];
	}
	// dfs
	for (int i = 1; i <= N; i++) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		v.clear();
		dfs(i, i);
	}
	cout << maxcnt << '\n';
	// check �� �͵� ���
	for (int i = 1; i <= N; i++) {
		if (check[i])
			cout << i << '\n';
	}
	return 0;
}