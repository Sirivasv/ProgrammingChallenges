#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pic;

const int MAXN = 1009;
const int MAXL = 209;

vector<pic> grafo[MAXN];

double memo[MAXN][MAXL];

int N, M;
string s;

double DP(int u, int ids) {
	if (u == (N - 1))
		return 100.0;
	if (ids == s.size())
		return 0.0;
	if (memo[u][ids] != -1.0)
		return memo[u][ids];
	double prob = 0.0, many = 0.0;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i].first;
		char c = grafo[u][i].second;
		if (c == s[ids]) {
			many += 1.0;
			prob += DP(v, ids + 1);
		}
	}
	if (many) 
		prob /= many;
	else
		prob = DP(u, ids + 1);
	return memo[u][ids] = prob;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXL; ++j)
			memo[i][j] = -1.0;
	for (int i = 0; i < M; ++i) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		u--, v--;
		grafo[u].push_back(pic(v, c));
		grafo[v].push_back(pic(u, c));
	}
	cin >> s;
	cout << fixed << setprecision(6) << DP(0, 0) << '\n';
	return 0;
}