#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
typedef pair<double, double> pdd;
pdd p[MAXN];
double d[MAXN][MAXN];
double memo[MAXN][MAXN];
int N;

inline double Dist (pdd ini, pdd fin) {
	return sqrt(((fin.first - ini.first) * (fin.first - ini.first)) + ((fin.second - ini.second) * (fin.second - ini.second)));
}

inline void limpiad() {
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) {
			memo[i][j] = -1.0;
			d[i][j] = Dist(p[i], p[j]);
		}
}

inline double DP(int p1, int p2) {
	int v = 1 + max(p1, p2);
	if (v == N - 1) return d[p1][v] + d[v][p2];
	if (memo[p1][p2] != -(1.0)) return memo[p1][p2];
	return memo[p1][p2] = min(d[p1][v] + DP(v, p2), d[v][p2] + DP(p1, v));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> N) {
		for (int i = 0; i < N; ++i) cin >> p[i].first >> p[i].second;
		limpiad();
		cout << fixed << setprecision(2) << DP(0, 0) << '\n';
	}
	return 0;
}