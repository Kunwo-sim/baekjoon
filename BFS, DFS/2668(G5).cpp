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
	// 시작 지점으로 돌아오면 중복 검사
	if (next == start) {
		bool overlap = false;
		// 중복 검사
		for (int i = 0; i < v.size(); i++) {
			if (check[v[i]] == true) {
				overlap = true;
				break;
			}
		}
		// 다른 부분과 중복되지 않으면 check 해주기
		if (!overlap) {
			for (int i = 0; i < v.size(); i++) {
				check[v[i]] = true;
			}
			maxcnt += cnt;
		}
	}
	// 다른 방문한 노드로 가는 경우에는 return
	else if (visited[next])
		return;
	// 방문하지 않았으면 dfs 재귀 호출
	else {
		dfs(start, next);
	}
}
int main() {
	// 입력
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
	// check 된 것들 출력
	for (int i = 1; i <= N; i++) {
		if (check[i])
			cout << i << '\n';
	}
	return 0;
}