#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int N, M, memo[60][60][60][60], acum[60][60];

inline int Range(int xi, int yi, int xj, int yj) {
	return acum[yj][xj] - acum[yj][xi - 1] - acum[yi - 1][xj] + acum[yi - 1][xi - 1];
}

inline int DP(int l, int r,  int u, int d) {
	if ((l == r) && (u == d)) return 0;
	if (memo[l][r][u][d]) return memo[l][r][u][d];
	int ans = INF;
	for (int k = l; k < r; ++k) ans = min(ans, DP(l, k, u, d) + DP(k + 1, r, u, d));
	for (int k = u; k < d; ++k) ans = min(ans, DP(l, r, u, k) + DP(l, r, k + 1, d));
	return memo[l][r][u][d] = ans + Range(l, u, r, d);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	int sum, aux;
	for (int i = 1; i <= N; ++i) {
		sum = 0;
		for (int j = 1; j <= M; ++j) {
			cin >> aux;
			sum += aux;
			acum[i][j] = acum[i - 1][j] + sum;
		}
	}
	cout << DP(1, M, 1, N) << '\n';
	return 0;
}