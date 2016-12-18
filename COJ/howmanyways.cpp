#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const long long MOD = 1000000000;
long long memo[MAXN][4], arr[MAXN];
int N;

inline int DP(int id, long long s) {
	if (id == N) return (s == 0);
	if (memo[id][s] != -1) return memo[id][s];
	return memo[id][s] = (DP(id + 1, s) + DP(id + 1, (s + arr[id]) % 3LL)) % MOD;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		for (int j = 0; j < 4; ++j) memo[i][j] = -1;
	}
	cout << (DP(0, 0LL) - 1LL + MOD) % MOD << '\n';
	return 0;
}