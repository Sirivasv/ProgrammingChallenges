#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M; 
	for (int i = 0; i < M; ++i) {
		if (i)
			cout << ' ';
		cout << (N - i);
	}
	for (int i = M; i < N; ++i) {
		if (i)
			cout << ' ';
		cout << (i - M + 1);
	}
	cout << '\n';
	return 0;
}