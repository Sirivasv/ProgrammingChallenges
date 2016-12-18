#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109;

int memo[MAXN][MAXN];
int price[MAXN][MAXN];
int c, m;

int DP(int idm, int manyl) {
	if ((manyl == 0) || (idm == m))
		return 0;
	if(memo[idm][manyl] != -1)
		return memo[idm][manyl];
	int lim = min(manyl, c);
	int mats = 0;
	for (int i = 0; i <= lim; ++i) 
		mats = max(mats, DP(idm + 1, manyl - i) + price[idm][i]);
	return memo[idm][manyl] = mats;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> c >> m;
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			memo[i][j] = -1;
	for (int i = 0; i < m; ++i)
		for (int j = 1; j <= c; ++j)
			cin >> price[i][j];
	cout << DP(0, c) << '\n';
	return 0;
}