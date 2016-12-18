#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef long long lli;

const lli MOD = 1000000007LL;
const int MAXN = 1009;

lli Fact[MAXN], C[MAXN][MAXN], IPOT[MAXN];

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

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int q;
	Fact[0] = 1LL;
	IPOT[0] = 1LL;
	lli Ba = 2LL;
	for (lli i = 1; i < MAXN; ++i) {
		Fact[i] = (Fact[i - 1] * i) % MOD;
		IPOT[i] = InvMod(Ba);
		Ba = (Ba * 2LL) % MOD;
	}
	
	C[0][0] = 1LL;
	for (int i = 1; i < MAXN; ++i) {
		C[i][0] = 1LL;
		for (int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	cin >> q;
	for (int nc = 0; nc < q; ++nc) {
		int N;
		cin >> N;
		set<int> mnn;
 		for (int i = 0; i < N; ++i) {
			int xi;
			cin >> xi;
			mnn.insert(xi);
		}
		lli repe = N - mnn.size();
		lli ans = (Fact[N] * IPOT[repe]) % MOD;
		cout << ans << " **\n";
		cout << repe << " ****\n";
		lli posans = 0;
		for (lli i = 1; i <= repe; ++i) {
			cout << C[repe][i] << ' ' << (Fact[N - i] * IPOT[repe - i]) % MOD << '\n';
			posans = (posans + (((C[repe][i]) * ((Fact[N - i] * IPOT[repe - i]) % MOD)) % MOD)) % MOD;
			//posans = (posans * IPOT[repe]) % MOD;
		}
		cout << posans << " ***\n";
		ans = (ans + MOD - posans) % MOD;
		cout << ans << '\n';
	}
    return 0;
}
