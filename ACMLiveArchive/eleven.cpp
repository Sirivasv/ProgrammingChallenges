#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXD = 15;
const int MAXN = 60;
const int MOD = 1000000007;
const int MAXS = 15;

int mn[MAXD];
ll C[MAXN][MAXN];
ll memo[MAXD][MAXN][MAXN][MAXS];

void PRECnR() {
	C[0][0] = 1LL;
	for (int i = 1; i < MAXN; ++i) {
		C[i][0] = 1LL;
		for (int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
}

void Limpia() {
	for (int i = 0; i < MAXD; ++i)
		for (int j = 0; j < MAXN; ++j)
			for (int k = 0; k < MAXN; ++k)
				for (int l = 0; l < MAXS; ++l)
					memo[i][j][k][l] = -1;
}

ll DP(int dig, int par, int impar, int sum) {
	if (dig == 10)
		return (sum == 0);
	if (memo[dig][par][impar][sum] != -1)
		return memo[dig][par][impar][sum];
	ll res = 0;
	for (int gp = 0; gp <= mn[dig]; ++gp) {
		int gim = mn[dig] - gp;
		if ((gp > par) || (gim > impar))
			continue;
		ll tmp = DP(dig + 1, par - gp, impar - gim, (sum + (gp * dig) + (10 * gim * dig)) % 11);
		tmp = (tmp * C[par][gp]) % MOD;		
		tmp = (tmp * C[impar][gim]) % MOD;
		res = (res + tmp) % MOD;
	}
	return memo[dig][par][impar][sum] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	PRECnR();
	string s;
	while (cin >> s) {
		for (int i = 0; i < 10; ++i)
			mn[i] = 0;
		int N = s.size();
		for (int i = 0; i < N; ++i) 
			mn[s[i] - '0']++;
		ll ans = 0;
		for (int i = 1; i < 10; ++i) {
			if (!mn[i])
				continue;
			mn[i]--;
			Limpia();
			ll tmp = DP(0, ((N + 1) / 2) - 1, N / 2, i);
			ans = (ans + tmp) % MOD;
			mn[i]++;
		}
		cout << ans << '\n';
	}
	return 0;
}