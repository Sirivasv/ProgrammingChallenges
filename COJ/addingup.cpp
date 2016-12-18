#include <bits/stdc++.h>
using namespace std;

typedef int lli;

const int MAXN = 260;
const lli MOD = (1000000007LL);

lli memo[MAXN][MAXN];

int N, K;

lli DP(int nk, int sum) {
	if ((sum == N) && (nk == K))
		return 1LL;
	
	if (nk > K)
		return 0;
	
	if (memo[nk][sum] != -1)
		return memo[nk][sum];
	
	lli many = 0;
	for (int i = 0; i <= N; ++i)
		if ((sum + i) <= N)
			many = (DP(nk + 1, sum + i) + many) % MOD;
		else
			break;
	
	return memo[nk][sum] = many;
}

void Limpia() {
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			memo[i][j] = -1;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		
		Limpia();
		
		cout << DP(0, 0) << '\n';
	}
	return 0;
}