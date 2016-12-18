#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 109;
const lli MOD = 100000000;

int memo[MAXN][MAXN][3];

int kf, kh;

lli DP(int fm, int hm, int tp) {
	if ((hm == 0) && (fm == 0))
		return 1;
	if ((fm == 0) && (tp == 0))
		return 0;
	if ((hm == 0) && (tp == 1))
		return 0;
	if (memo[fm][hm][tp] != -1)
		return memo[fm][hm][tp];
	int lim;
	lli res = 0;
	if (tp == 0) {
		lim = min(fm, kf);
		for (int i = 1; i <= lim; ++i)
			res = (res + DP(fm - i, hm, 1)) % MOD;
	} else {
		lim = min(hm, kh);
		for (int i = 1; i <= lim; ++i)
			res = (res + DP(fm, hm - i, 0)) % MOD;
	}
	return memo[fm][hm][tp] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			for (int k = 0; k < 3; ++k)
				memo[i][j][k] = -1;
	int nf, nh;
	cin >> nf >> nh >> kf >> kh;
	cout << ((DP(nf, nh, 0) + DP(nf, nh, 1)) % MOD) << '\n';
	return 0;
}