#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<long long> v;

void fun(int target) {
	queue<long long> q;
	for (int i = 0; i <= 9; i++) {
		q.push(i);
		v.push_back(i);
	}
	while (!q.empty()) {
		long long num = q.front();
		// 맨 끝에서 가져오기
		int last = num % 10;
		q.pop();
		// 끝자리 보다 작은 수 뒤에 넣고 q에 push
		for (int i = 0; i < last; i++) {
			long long newnum = num * 10 + i;
			q.push(newnum);
			v.push_back(newnum);
		}
	}
	// 범위 초과
	if (target >= v.size()) {
		cout << -1;
	}
	else {
		cout << v[target];
	}
}

int main() {
	int N;
	cin >> N;
	fun(N);
	return 0;
}