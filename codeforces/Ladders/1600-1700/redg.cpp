#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200009;
const lli MOD = ((lli)1e9) + 7LL;

int R, G, maT, vis[5][MAXN], ID;
lli memo[5][MAXN];

void mDP() {
	
	for (int i = 0; i < MAXN; ++i)
		memo[1][i] = 901;
	
	for (int i = 900; i >= 0; --i)
		for (int j = MAXN - 1; j >= 0; --j) {
			int nxt = i & 1;
			int cur = nxt ^ 1;
			if (R < j) {
				memo[nxt][j] = 0;
				continue;
			}
			int cg = (((i * (i + 1)) / 2) - j);
			if (G < cg) {
				memo[nxt][j] = 0;
				continue;
			}
			
			lli mats = i;
			if ((j + (i + 1)) <= R)
				mats = max(mats, memo[cur][j + (i + 1)]);
			if ((cg + (i + 1)) <= G) 
				mats = max(mats, memo[cur][j]);
			memo[nxt][j] = mats;
			
		}
		maT = memo[0][0];
} 

int cDP() {
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < MAXN; ++j)
			memo[i][j] = 0;
 	for (int i = maT; i >= 0; --i)
		for (int j = MAXN - 1; j >= 0; --j) {
			int nxt = i & 1;
			int cur = nxt ^ 1;
			if (R < j) {
				memo[nxt][j] = 0;
				continue;
			}
			int cg = (((i * (i + 1)) / 2) - j);
			if (G < cg) {
				memo[nxt][j] = 0;
				continue;
			}
			
			lli res = (i == maT);
			if ((j + (i + 1)) <= R)
				res += memo[cur][j + (i + 1)];
			if ((cg + (i + 1)) <= G)
				res += memo[cur][j];
			
			memo[nxt][j] = res % MOD;
		}
		
		return memo[0][0];
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> R >> G;
	
	mDP();
	//cout << maT << '\n';
	cout << cDP() << '\n';
	
	return 0;
}