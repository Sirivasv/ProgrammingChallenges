#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 1000009;
const lli MOD = 1000000007LL;

lli arr[MAXN];
lli C[MAXN];
lli xd[MAXN];

lli Exponenciar(lli a,lli n,lli m){
	lli resultado = 1LL;
	for(; n ; n >>= 1LL){
		if(n&1LL) resultado = (resultado*a)%m;
		a = (a*a)%m;
	}
	return resultado;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli N, mxi = -1LL;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		mxi = max(mxi, arr[i]);
		C[arr[i]]++;
	}

	for (int i = 1; i <= mxi; ++i) {
		int lim = mxi / i;
		for (int j = 2; j <= lim; ++j) {
			C[i] += C[i * j];
		}
	}

	lli res = 0;

	for (int i = mxi; i >= 1; --i) {
		int lim = mxi / i;
		xd[i] = (Exponenciar(2LL, C[i], MOD) - 1LL + MOD) % MOD;
		for (int j = 2; j <= lim; ++j) {
			xd[i] = (xd[i] - xd[i * j] + MOD) % MOD;
		}
		res = (res + ((lli(i) * xd[i]) % MOD)) % MOD;
	}

	cout << res << '\n';

	return 0;
}