//Div 2 B - DP reconstruccion
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;

int memo[MAXN], ans[MAXN], idx, cost[15];

int DP(int ple) {
	if (memo[ple] != -1) return memo[ple];
	int mats = 0;
	for (int i = 9; i >= 1; --i) 
		if (ple >= cost[i])
			mats = max(mats, DP(ple - cost[i]) + 1);
	return memo[ple] = mats;
}

void reconstruccion (int ple) {
	for (int i = 9; i >= 1; --i)
		if (ple >= cost[i])
			if ((DP(ple - cost[i]) + 1) == (DP(ple))) {
				ans[idx++] = i;
				reconstruccion(ple - cost[i]);
				return;
			}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	for (int i = 0; i < MAXN; ++i) memo[i] = -1;

	cin >> N;

	for (int i = 1; i < 10; ++i) cin >> cost[i];

	if (DP(N) == 0) {
		cout << "-1\n";
		return 0;
	}

	reconstruccion(N);

	for (int i = 0; i < idx; ++i) cout << ans[i];

	cout << '\n';

	return 0;
}