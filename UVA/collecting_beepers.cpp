#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1000000000;
const int MAXN = 12;

int C[MAXN][MAXN], memo[MAXN][(1 << MAXN)], full_mask;
pii beep[MAXN];

inline int Abs (int x) { return ((x < 0)?(-x):(x)); }
inline int ManDist(pii ini, pii fin) { return Abs(ini.first - fin.first) + Abs(ini.second - fin.second); }

int main() {
	int N, T, R, Col;
	cin >> T;
	while (T--) {
		cin >> Col >> R;
		cin >> beep[0].first >> beep[0].second;
		cin >> N;
		for (int i = 1; i <= N; ++i) cin >> beep[i].first >> beep[i].second;
		N++;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				C[i][j] = ManDist(beep[i], beep[j]);
		full_mask = (1 << N) - 1;
		for (int i = 1; i < N; ++i) memo[i][full_mask] = C[i][0];
		for (int mask = full_mask - 1; mask >= 1; mask--)
			for (int id = 0; id < N; ++id) {
				if (!(mask & (1 << id))) continue;
				memo[id][mask] = INF;
				for (int k = 1; k < N; ++k) 
					if (!(mask & (1 << k))) 
						memo[id][mask] = min(memo[id][mask], memo[k][mask | (1 << k)] + C[id][k]);
			}
		cout << "The shortest path has length " << memo[0][1] << '\n';
	}
	return 0;
}