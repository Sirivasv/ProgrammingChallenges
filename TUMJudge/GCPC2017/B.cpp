#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1000000007;;

lli Expo(lli b, lli e) {
	lli res = 1LL;
	for (; e; e >>= 1) {
		if (e & 1) res = (res * b) % MOD;
		b = (b * b) % MOD;
	}
	return res;
}

lli InvDiv(lli xi) { return Expo(xi, MOD - 2LL); }

int main() {
	lli N, M, C;
	cin >> N >> M >> C;
	lli CN2 = Expo(C, N * N);
	//cout << CN2 << '\n';
	lli CN2M = Expo(CN2, M);
	//cout << CN2M << '\n';
	lli DIV = InvDiv(M);
	lli UDIV = (CN2M - CN2 + MOD) % MOD;
	lli res = (((UDIV * DIV) % MOD) + CN2) % MOD;
	cout << res << '\n';
	return 0;
}