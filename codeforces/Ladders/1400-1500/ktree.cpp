#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1000000007LL;

const int MAXN = 105;

lli memo[MAXN][5];
int N, K, d;

lli DP(int sum, int fla) {
	if ((sum == N) && fla)
		return 1LL;
	if (sum == N)
		return 0LL;
	if (memo[sum][fla] != -1)
		return memo[sum][fla];
	lli res = 0;
	for (int i = 1; i <= K; ++i)
		if ((sum + i) <= N)
			res = (res + DP(sum + i, fla || (i >= d))) % MOD;
	return memo[sum][fla] = res;
} 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < 3; ++j)
			memo[i][j] = -1;
	cin >> N >> K >> d;
	cout << DP(0, 0) << '\n';
	return 0;
}