#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2000];
bool visited[2000];
bool ispossible;

void dfs(int node, int depth) {
	if (depth == 4) {
		// 깊이가 4가 되면 ABCDE를 만족한다.
		ispossible = true;
		return;
	}
	visited[node] = true;
	// DFS
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (!visited[next] && !ispossible) {
			dfs(next, depth + 1);
		}
	}
	visited[node] = false;
}

int N, M;
int main() {
	cin >> N >> M;
	// 그래프 처리
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		dfs(i, 0);
		if (ispossible) {
			break;
		}
	}
	cout << ispossible;
	return 0;
}