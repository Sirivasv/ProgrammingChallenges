#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 1000009;
const lli MOD = 1000000007LL;

lli Fact[MAXN];

inline lli Euclides(lli a, lli b, lli& x, lli& y) {
    if (!b) { x = 1, y = 0; return a; }
    lli gcd = Euclides(b, a % b, x, y);
    x = !MOD? x - y * (a / b):
        (MOD + x - (y * (a / b)) % MOD) % MOD;
    swap(x, y);
    return gcd;
}

inline lli InvMod(lli x) {
	lli res, tmpy;
	Euclides(x, MOD, res, tmpy);
	return res;
}

lli Cnr(lli n, lli r) {
	return (((Fact[n]) * (InvMod((Fact[n - r] * Fact[r]) % MOD))) % MOD);
}

lli a, b, N;

bool IsGood(lli n) {
	if (n == 0)
		return false;
	while (n) {
		if (((n % 10) != a) && ((n % 10) != b))
			return false;
		n /= 10;
	}
	return true;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	Fact[0] = 1LL;
	for (lli i = 1LL; i < MAXN; ++i)
		Fact[i] = (Fact[i - 1] * i) % MOD;
	
	cin >> a >> b >> N;
	lli ans = 0;
	for (lli i = 0; i <= N; ++i)
		if (IsGood((a * i) + (b * (N - i))))
			ans = (ans + Cnr(N, i)) % MOD;
	cout << ans << '\n';
	return 0;
}