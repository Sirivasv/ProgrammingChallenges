#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int mats = 1000000;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		mats = min(b - a + 1, mats);
	}
	cout << mats << '\n';
	for (int i = 0; i < N; ++i) { 
		if (i)
			cout << ' ';
		cout << (i % mats);
	}
	cout << '\n';
	return 0;
}