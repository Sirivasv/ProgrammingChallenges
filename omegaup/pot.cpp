#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
long long N, K, S, ax;

long long BinPot(long long x, long long y) {
	if (x <= 1LL) return 1LL;
	long long res = 1, p = x;
	for (; y; y >>= 1) {
		if (y & 1) res = (res * p) % MOD;
		p = (p * p) % MOD;
	}
	return res;
}

long long BinMul(long long x, long long y) {
	if (y == 1LL) return x;
	long long res = 0, p = x;
	for (; y; y >>= 1) {
		if (y & 1) res = (res + p) % MOD;
		p = (p + p) % MOD;
	}
	return res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> ax;
		S += ax;
	}
	cout << BinMul(S, BinPot(--N, K)) << '\n';
	return 0;
}