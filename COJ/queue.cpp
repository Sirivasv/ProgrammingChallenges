#include <bits/stdc++.h>
using namespace std;

typedef int lli;

const int MAXN = 2090;
const lli MOD = 1000000007LL;

lli memo[MAXN][MAXN];

int D, C, S, limc, limd;

lli DP(int mc, int md) {
	if ((mc == limc) && (md == limd))
		return 1LL;
	
	if (memo[mc][md] != -1)
		return memo[mc][md];
	
	lli many = 0;
	
	if (mc < limc)
		many = (DP(mc + 1, md) + many) % MOD;
	
	if ((md < limd) && ((mc - md) >= 1))
		many = (DP(mc, md + 1) + many) % MOD;
	
	return memo[mc][md] = many;
}

void Limpia() {
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			memo[i][j] = -1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> C >> D >> S;
	limc = C + S;
	limd = D;
	Limpia();
	
	cout << DP(S, 0) << '\n';
	return 0;
}