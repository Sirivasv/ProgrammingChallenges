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

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> N) {
		for (int i = 0; i < N; ++i) cin >> p[i].first >> p[i].second;
		limpiad();
		//cout << fixed << setprecision(2) << DP(0, 0) << '\n';
		for (int i = N - 2; i >= 0; --i) {
			for (int j = N - 2; j >= 0; --j) {
				if ((i == j) && (i) && (j))continue;
				int p1, p2, v;
				//parte 1
				p1 = i; p2 = j;
				v = 1 + max(p1, p2);
				if (memo[p1][p2] == -(1.0)) {
					if (v == N - 1) memo[p1][p2] = d[p1][v] + d[v][p2];
					else memo[p1][p2] = min(d[p1][v] + memo[v][p2], d[v][p2] + memo[p1][v]);
				}
				//parte 2
				p1 = j; p2 = i;
				v = 1 + max(p1, p2);
				if (memo[p1][p2] == -(1.0)) {
					if (v == N - 1) memo[p1][p2] = d[p1][v] + d[v][p2];
					else memo[p1][p2] = min(d[p1][v] + memo[v][p2], d[v][p2] + memo[p1][v]);
				}
			}
		}
		cout << fixed << setprecision(2) << memo[0][0] << '\n';
	}
	return 0;
}