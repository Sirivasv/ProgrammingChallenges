#include <bits/stdc++.h>
using namespace std;

typedef int lli;

const lli MOD = 1000000007LL;
const int MAXN = 5005;

lli dp[5][MAXN];

int Abs(int x) { return ((x < 0)?(-x):(x)); }

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N, a, b, k;
	
	cin >> N >> a >> b >> k;
	
	a--; b--;
	
	dp[0][a] = 1;
	
	for (int i = 0; i < k; ++i) {
		int curi = i & 1;
		int nxt = curi ^ 1;
		
		for (int j = 0; j < N; ++j) dp[nxt][j] = 0;
		
		for (int j = 0; j < N; ++j) {
			lli val = dp[curi][j];
			int offv = Abs(j - b);
			dp[nxt][max(j - offv + 1, 0)] = (((dp[nxt][max(j - offv + 1, 0)] + val) % MOD) + MOD) % MOD;
			dp[nxt][min(j + offv, N)] = (((dp[nxt][min(j + offv, N)] - val) % MOD) + MOD) % MOD;
		}
		
		for (int j = 1; j < N; ++j) dp[nxt][j] = (((dp[nxt][j] + dp[nxt][j - 1]) % MOD) + MOD) % MOD;
		
		for (int j = 0; j < N; ++j) dp[nxt][j] = (((dp[nxt][j] - dp[curi][j]) % MOD) + MOD) % MOD;
		
	}
	
	lli ans = 0;
	for (int i = 0; i < N; ++i) ans = ((ans + dp[k & 1][i]) % MOD + MOD) % MOD;
	
	cout << ans << '\n';
	
	return 0;
}