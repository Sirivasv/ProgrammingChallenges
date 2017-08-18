#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2509;
double memo[MAXN][MAXN][2], arista[MAXN][MAXN];
int flag[MAXN][MAXN][2], n, m;

inline int F(int izq, int der, int id) {
	if (flag[izq][der][id]) return memo[izq][der][id];
	flag[izq][der][id] = 1;
	int n_i = (izq - 1 + n) % n;
	int n_d = (der + 1) % n;
	int nodo = ((id)?(der):(izq));
	if (n_i == n_d) return arista[izq][der][id];
	double ans = -1.0;
	ans = max(ans, F(n_i, der, 0));
	ans = max(ans, F(izq, n_d, 1));
	return memo[izq][der][id] = ans;
}

double Xi[MAXN], Yi[MAXN];

inline double Dist(int i, int j) { return (sqrt(((Yi[j] - Yi[i]) * (Yi[j] - Yi[i]) + ((Xi[j] - Xi[i]) * (Xi[j] - Xi[i]) ))); }

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> Xi[i] >> Yi[i];
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		double dist = Dist(i, j);
		arista[i][j] = arista[j][i] = Dist(i, j);
	}
	double ans = -3;
	for (int i = 0; i < n; ++i) ans = max(ans, F(i, i, 0));
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}