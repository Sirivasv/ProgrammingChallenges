#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int N, M, memo[60][60][60][60], acum[60][60];

inline int Range(int xi, int yi, int xj, int yj) {
	return acum[yj][xj] - acum[yj][xi - 1] - acum[yi - 1][xj] + acum[yi - 1][xi - 1];
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
	for (int sideH = 1; sideH <= M; ++sideH) 
		for (int sideV = 1; sideV <= N; ++sideV)
			for (int l = 1; (l + sideH - 1) <= M; ++l) {
				int r = l + sideH - 1;
				for (int u = 1; (u + sideV - 1) <= N; ++u) {
					int d = u + sideV - 1;
					if ((sideH == 1) && (sideV == 1)) {
						memo[l][r][u][d] = 0;
						continue;
					}
					int ans = INF;
					for (int k = l; k < r; ++k) ans = min(ans, memo[l][k][u][d] + memo[k + 1][r][u][d]);
					for (int k = u; k < d; ++k) ans = min(ans, memo[l][r][u][k] + memo[l][r][k + 1][d]);
					memo[l][r][u][d] = ans + Range(l, u, r, d);	
				}
			}
	cout << memo[1][M][1][N] << '\n';
	return 0;
}