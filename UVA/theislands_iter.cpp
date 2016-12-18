#include <bits/stdc++.h>
using namespace std;
const int MAXN = 109;
typedef pair<double, double> pdd;
pdd p[MAXN];
double d[MAXN][MAXN];
double memo[MAXN][MAXN][3][3];
int N, sp, spp;
queue<int> leftt;
stack<int> rightt;

inline double Dist (pdd ini, pdd fin) {
	return sqrt(((fin.first - ini.first) * (fin.first - ini.first)) + ((fin.second - ini.second) * (fin.second - ini.second)));
}

inline void limpiad() {
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 3; ++k)
				for (int l = 0; l < 3; ++l)
					memo[i][j][k][l] = -1.0;
			d[i][j] = Dist(p[i], p[j]);
		}
}

inline void reDP(int p1, int p2, int spe1, int spe2) {
	int v = 1 + max(p1, p2);
	if (v == N - 1) {
		leftt.push(v);
		return;
	}
	if (((v == sp) || (v == spp)) && (spe1 || spe2)) {
		if (spe1) {
			rightt.push(v);
			reDP(p1, v, spe1, spe2 + 1);
			return;
		} else {
			leftt.push(v);
			reDP(v, p2, spe1 + 1, spe2);
			return;
		}
	}
	double a = d[p1][v] + memo[v][p2][spe1 + ((v == sp) || (v == spp))][spe2];
	double b = d[v][p2] + memo[p1][v][spe1][spe2 + ((v == sp) || (v == spp))];
	if (b < a) {
		rightt.push(v);
		reDP(p1, v, spe1, spe2 + ((v == sp) || (v == spp)));
	} else {
		leftt.push(v);
		reDP(v, p2, spe1 + ((v == sp) || (v == spp)), spe2);
	}
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int nc = 1;
	while (nc) {
		cin >> N >> sp >> spp;
		if (!(N | sp | spp)) break;
		for (int i = 0; i < N; ++i) cin >> p[i].first >> p[i].second;
		limpiad();
		//cout << "Case " << nc++ << ": " << fixed << setprecision(2) << DP(1, 0, ((1 == sp) || (1 == spp)), 0) + d[0][1] << '\n';
		
		//BEGIN ITER
		for (int spe2 = 1; spe2 >= 0; --spe2) {
			for (int spe1 = 1; spe1 >= 0; --spe1) {
				for (int i = N - 2; i >= 0; --i) {
					for (int j = N - 2; j >= 0; --j) {
						if (i == j) continue;
						int p1, p2, v;
						//parte 1
						p1 = i; p2 = j;
						v = 1 + max(p1, p2);
						if (memo[p1][p2][spe1][spe2] == -(1.0)) {
							if (v == N - 1) memo[p1][p2][spe1][spe2] = d[p1][v] + d[v][p2];
							else {
								if (((v == sp) || (v == spp)) && (spe1 || spe2)) {
									if (spe1) memo[p1][p2][spe1][spe2] = d[v][p2] + memo[p1][v][spe1][spe2 + 1];
									else memo[p1][p2][spe1][spe2] = d[p1][v] + memo[v][p2][spe1 + 1][spe2];
								} else memo[p1][p2][spe1][spe2] = min(d[p1][v] + memo[v][p2][spe1 + ((v == sp) || (v == spp))][spe2], d[v][p2] + memo[p1][v][spe1][spe2 + ((v == sp) || (v == spp))]);
							}
						}
						//parte 2
						p1 = j; p2 = i;
						v = 1 + max(p1, p2);
						if (memo[p1][p2][spe1][spe2] == -(1.0)) {
							if (v == N - 1) memo[p1][p2][spe1][spe2] = d[p1][v] + d[v][p2];
							else {
								if (((v == sp) || (v == spp)) && (spe1 || spe2)) {
									if (spe1) memo[p1][p2][spe1][spe2] = d[v][p2] + memo[p1][v][spe1][spe2 + 1];
									else memo[p1][p2][spe1][spe2] = d[p1][v] + memo[v][p2][spe1 + 1][spe2];
								} else memo[p1][p2][spe1][spe2] = min(d[p1][v] + memo[v][p2][spe1 + ((v == sp) || (v == spp))][spe2], d[v][p2] + memo[p1][v][spe1][spe2 + ((v == sp) || (v == spp))]);
							}
						}
					}
				}
			}
		}

		
		//END ITER
		cout << "Case " << nc++ << ": " << fixed << setprecision(2) << memo[1][0][((1 == sp) || (1 == spp))][0] + d[0][1] << '\n';
		reDP(1, 0, ((1 == sp) || (1 == spp)), 0);
		cout << "0 1 ";
		while (!leftt.empty()) {
			cout << leftt.front() << ' ';
			leftt.pop();
		}
		while (!rightt.empty()) {
			cout << rightt.top() << ' ';
			rightt.pop();
		}
		cout << "0\n";
	}
	return 0;
}
/*
Caso Maestro para uDebug
6 1 4
1 3
3 4
4 1
7 5
8 3
5 5
5 4 2
0 10
3 14
4 7
7 10
8 12
7 2 3
0 0
2 3
3 3
4 0
5 2
6 0
7 1
5 1 3
2 3
3 3
4 4
5 3
6 3
11 8 9
0 0
1 1
2 7
7 9
10 45
15 5
16 6
17 7
18 8
19 9
23 22
0 0 0
*/