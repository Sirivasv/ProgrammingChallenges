#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	lli N;
	cin >> N;
	if (N % 2)
		cout << (lli)(((((N - 1LL) >> 1) * ((N - 1LL) >> 1)) + (((N + 1LL) >> 1) * ((N + 1LL) >> 1)))) << '\n';
	else 
		cout << ((N * N) >> 1) << '\n';
	lli cnt = 0;
	for (int i = 0; i < N; ++i) {
		cnt = (i & 1);
		for (int j = 0; j < N; ++j, ++cnt)
			cout << ((cnt % 2LL)?('.'):('C'));
		cout << '\n';
	}

	return 0;
}