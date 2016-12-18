#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int memo[MAXN][MAXN], corteH[MAXN], corteV[MAXN], limH, limV;

inline int DP(int H, int V) {
	if ((H == limH) && (V == limV)) return 0;
	if (memo[H][V]) return memo[H][V];
	if (V == limV) return memo[H][V] = DP(H + 1, V) + ((V + 1) * corteH[H]);
	if (H == limH) return memo[H][V] = DP(H, V + 1) + ((H + 1) * corteV[V]);
	return memo[H][V] = min(DP(H + 1, V) + ((V + 1) * corteH[H]), DP(H, V + 1) + ((H + 1) * corteV[V]));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> M >> N;
	limV = M - 1;
	for (int i = 0; i < limV; ++i) cin >> corteV[i];
	sort(corteV, corteV + limV, greater<int>());
	limH = N - 1;
	for (int i = 0; i < limH; ++i) cin >> corteH[i];
	sort(corteH, corteH + limH, greater<int>());
	cout << DP(0, 0) << '\n';
	return 0;
}