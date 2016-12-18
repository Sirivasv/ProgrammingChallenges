#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int INF = 1000000000;
int N, M, nc, a, b, c, d[MAXN][MAXN], dp[2][1 << MAXN][MAXN]; 

inline void Limpia(){
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) d[i][j] = INF;
		for (int k = 0; k < 2; ++k)
			for (int j = 0; j < (1 << N); ++j) dp[k][j][i] = INF; 
	}
}

inline void Calc(int idx) {
	if (idx) dp[idx][1 << (N - 1)][N - 1] = 0;
	else dp[idx][1][0] = 0;
	for (int i = 1; i < (1 << N); ++i)
		for (int j = 0; j < N; ++j) {
			if (dp[idx][i][j] == INF) continue;
			for (int k = 0; k < N; ++k) {
				if((i >> k) & 1) continue;
				int ni = (i | (1 << k));
				dp[idx][ni][k] = min(dp[idx][ni][k], dp[idx][i][j] + d[j][k]);
			}
		}
}

inline void CalcDist() {
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N) {
		cin >> M;
		Limpia();
		for (int i = 0; i < M; ++i) {
			cin >> a >> b >> c;
			d[a][b] = c;
			d[b][a] = c;
		}
		CalcDist();
		//for (int i = 0; i < N; ++i,  cout << '\n') for (int j = 0; j < N; ++j) cout << adjmtr[i][j] << ' ';
		Calc(0);
		Calc(1);
		int ans = INF;
		if (N == 3) {
			cout << "Case " << ++nc << ": " << dp[0][7][2] + dp[1][7][0] << '\n';
			continue;
		}
		for (int i = 0; i < (1 << N); ++i) {
			if (!(i & 1)) continue;
			if (((i >> (N - 1)) & 1)) continue;
			if (__builtin_popcount(i) != (N >> 1)) continue;
			int ecode = ((1 << N) - 1) ^ i;
			for (int j = 1; j < N - 1; ++j) {
				if (!((i >> j) & 1)) continue;
				for (int k = 1; k < N - 1; ++k) {
					if (!((i >> k) & 1)) continue;
					ans = min(ans, dp[0][i][j] + dp[1][ecode | (1 << j)][j] + dp[1][(i - 1) | (1 << (N - 1))][k] + 
					          dp[0][((ecode ^ (1 << N - 1)) | 1) | (1 << k)][k]);
				}
			}
		}
		cout << "Case " << ++nc << ": " <<  ans << '\n';
	}
	return 0;
}