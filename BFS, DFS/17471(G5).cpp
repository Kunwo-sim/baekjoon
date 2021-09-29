#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int popul[11];
int N;
int zerosum, onesum;
bool graph[11][11];
bool divide[11];
bool visited[11];
int minsub = 987654321;

// ����Ǿ� �ִ��� Ȯ��
bool checkConnect(int curnode, bool division, int target) {
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(curnode);
	visited[curnode] = true;
	int t_size = 0;
	while (!q.empty()) {
		int cur = q.front();
		t_size++;
		if (division == false) {
			zerosum += popul[cur];
		}
		else {
			onesum += popul[cur];
		}
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (graph[cur][i] == true && !visited[i] && divide[i] == division)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	if (t_size == target)
		return true;
	else
		return false;
}

void selectnode(int node, int cnt, int size) {
	// size��ŭ ���� 0, 1���� ����Ǵ��� �˻�
	if (cnt == size) {
		int zerostart = 0, onestart = 0;
		bool isConnectZero, isConnectOne;
		// 0 ������ ��ŸƮ���
		for (int i = 1; i <= N; i++) {
			if (divide[i] == false) {
				zerostart = i;
				break;
			}
		}
		// 1 ������ ��ŸƮ���
		for (int i = 1; i <= N; i++) {
			if (divide[i] == true) {
				onestart = i;
				break;
			}
		}
		// 0 �˻�
		zerosum = 0;
		isConnectZero = checkConnect(zerostart, 0, N - size);
		// 1 �˻�
		onesum = 0;
		isConnectOne = checkConnect(onestart, 1, size);
		// �� �� ����Ǿ� ������ �ּڰ� ����
		if (isConnectOne && isConnectZero) {
			minsub = min(minsub, abs(zerosum - onesum));
		}
		return;
	}
	// size��ŭ �� �� ���� �ݺ�
	for (int i = node; i <= N; i++) {
		if (divide[i] == true)
			continue;
		divide[i] = true;
		selectnode(i + 1, cnt + 1, size);
		divide[i] = false;
	}
}
void fun() {
	for (int i = 1; i <= N; i++) {
		// ������ 0, 1�� ����
		selectnode(1, 0, i);
	}
	if (minsub == 987654321)
		cout << -1;
	else
		cout << minsub;
}

int main() {
	// �Է�
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> popul[i];
	}
	// �׷��� ����
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int node;
			cin >> node;
			graph[i][node] = true;
		}
	}
	fun();
	return 0;
}