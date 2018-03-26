#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1e9 + 7;

lli Euclides( lli a, lli b, lli& x, lli & y, lli mod = 0 ){
	if(!b){
		x = 1; y = 0;return a;
	}
	lli gcd = Euclides(b, a%b, x, y, mod);
	x = !mod ? x - y * (a/b) :
		(mod + x - (y * (a/b)) % mod)% mod;
	swap(x, y);
	return gcd;
}

lli Inv(lli vi) {
	lli inv, yi;
	Euclides(vi, MOD, inv, yi, MOD);
	return inv;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	lli vali = 0LL;
	lli fact = 1LL;
	lli deno = 1LL;

	for (int i = 1; i <= N; ++i) {
		lli ai;
		cin >> ai;
		vali = (vali + ai + 1LL) % MOD;
		deno = (deno * vali) % MOD;
		fact = (fact * i) % MOD;
	}

	cout << ((fact * Inv(deno)) % MOD) << '\n';

	return 0;
}