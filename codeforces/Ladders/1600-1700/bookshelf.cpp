#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 109;
const int MAXW = 20009;
const int INF = 1000;

pii arr[MAXN];

int memo[MAXN][MAXW][5], N;

int DP(int pos, int w, int f) {
	if ((pos == N) && (w >= 10000) && (f)) return 0;
	if (pos == N) return INF;
	if (memo[pos][w][f] != -1) return memo[pos][w][f];
	return memo[pos][w][f] = min(DP(pos + 1, w + arr[pos].first, f | 1) + arr[pos].first, DP(pos + 1, w - arr[pos].second, f));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXW; ++j)
			for (int k = 0; k < 2; ++k)
				memo[i][j][k] = -1;
	cout << DP(0, 10000, 0) << '\n';
	return 0;
}