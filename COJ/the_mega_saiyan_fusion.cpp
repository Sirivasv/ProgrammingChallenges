#include <bits/stdc++.h>
using namespace std;
const int MAXN = 509;
const int INF = 10000000;
int ki, acum[MAXN], memo[MAXN][MAXN];

inline int DP (int l, int r) {
	if (memo[l][r]) return memo[l][r];
	if (l == r) return memo[l][r] = 0;
	memo[l][r] = INF;
	for (int k = l; k < r; ++k)
		memo[l][r] = min(memo[l][r], DP(l, k) + DP(k + 1, r) + max(acum[k] - acum[l - 1], acum[r] - acum[k]));
	return memo[l][r];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int S;
	cin >> S;
	for (int i = 1; i <= S; ++i) {
		cin >> ki;
		acum[i] = acum[i - 1] + ki;
	}
	cout << DP(1, S) << '\n'; 
	return 0;
} 