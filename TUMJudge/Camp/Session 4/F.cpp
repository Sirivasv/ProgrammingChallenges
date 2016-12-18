#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli arr[10];

lli Exp(lli b, lli e) {
	if (e == 0)
		return 1LL;
	lli res = b;
	while(--e) {
		res *= b;
	}
	return res;
}

void F(lli N, lli c) {
	lli lim = N * N;
	if (N == 1) {
		arr[0] = arr[1] = arr[2] = c;
	} else if (N == 2) {
		arr[0] = Exp(c, lim);
		arr[1] = (Exp(c, lim) + (2LL * Exp(c, lim / 4LL)) + Exp(c, lim / 2LL)) / 4LL;
		arr[2] = (Exp(c, lim) + (2LL * Exp(c, lim / 4LL)) + (3LL * Exp(c, lim / 2LL)) + (2LL * Exp(c, 3LL))) / 8LL;
	} else if (N == 3) {
		arr[0] = Exp(c, lim);
		arr[1] = (Exp(c, lim) + (2LL * Exp(c, 3LL)) + Exp(c, 5LL)) / 4LL;
		arr[2] = (Exp(c, lim) + (2LL * Exp(c, 3LL)) + (4LL * Exp(c, 6LL)) + (1LL * Exp(c, 5LL))) / 8LL;
	} else if (N == 4) {
		arr[0] = Exp(c, lim);
		arr[1] = (Exp(c, lim) + (2LL * Exp(c, lim / 4LL)) + Exp(c, lim / 2LL)) / 4LL;
		arr[2] = (Exp(c, lim) + (2LL * Exp(c, lim / 4LL)) + (3LL * Exp(c, lim / 2LL)) + (2LL * Exp(c, 10LL))) / 8LL;
	} else {
		arr[0] = Exp(c, lim);
		arr[1] = (Exp(c, lim) + (2LL * Exp(c, 7LL)) + Exp(c, 13LL)) / 4LL;
		arr[2] = (Exp(c, lim) + (2LL * Exp(c, 7LL)) + (4LL * Exp(c, 15LL)) + Exp(c, 13LL)) / 8LL;
	}
} 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int N, K, C;
		cin >> N >> K >> C;
		F(N, C);
		cout << "Case #" << nc << ": " << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
	}
	return 0;
}