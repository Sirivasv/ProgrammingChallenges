#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long lli;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		lli N, pos, offset = 0;
		cin >> N >> pos;
		for (int i = 0; i < N; ++i) {
			if (pos & 1) offset += (1LL << (N - i - 1));
			pos >>= 1;
		}
		cout << (pos + offset) << '\n';
	}

	return 0;
}