#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 유클리드 호제법
int GCD(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return GCD(b, a % b);
}

int main() {
	int N;
	cin >> N;
	vector<int> v;
	// 입력
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	int gcd = abs(v[1] - v[0]);
	for (int i = 2; i < v.size(); i++) {
		gcd = GCD(gcd, abs(v[i] - v[i - 1]));
	}

	vector<int> result;
	for (int i = 2; i * i <= gcd; i++) {
		if (gcd % i == 0) {
			result.push_back(i);
			if (gcd / i != i) {
				result.push_back(gcd / i);
			}
		}
	}
	result.push_back(gcd);
	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	return 0;
}