#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 2; i <= N; ++i)
			cout << i << ' ';
		cout << 1 << '\n';
	}
	return 0;
}