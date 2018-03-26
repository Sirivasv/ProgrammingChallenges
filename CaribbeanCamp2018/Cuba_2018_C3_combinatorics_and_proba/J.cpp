#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1e9 + 7;
const int MAXN = 1e5;

lli P[MAXN], Q[MAXN];

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
	lli resP = 1LL, resQ = 1LL, ans = 0LL;
	for (int i = 0; i < N; ++i) cin >> P[i] >> Q[i];
	for (int i = N - 1; i >= 0; --i) {
		resP = (resP * P[i]) % MOD;
		resQ = (resQ * Q[i]) % MOD;
		ans = (ans + (resQ * Inv(resP))) % MOD;
	}
	
	cout << ans << '\n';

	return 0;
}