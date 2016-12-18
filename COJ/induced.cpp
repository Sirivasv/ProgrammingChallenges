#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50009;
const int MAXE = 55;

int memo[MAXN][MAXE];
int FX[MAXN], parent[MAXN], Mcost[MAXE][MAXE];
vector<int>grafo[MAXN];
int N, E;

int DP(int u, int pe) {
	if (memo[u][pe] != -1)
		return memo[u][pe];
	int res = 100000000;
	if (FX[u]) {
		int pres = Mcost[pe][FX[u]];
		for (int j = 0; j < grafo[u].size(); ++j) {
			int v = grafo[u][j];
			if (v != parent[u])
				pres += DP(v, FX[u]);
		}
		res = min(res, pres);
	} else {
		for (int i = 1; i <= E; ++i) {
			int pres = Mcost[pe][i];
			for (int j = 0; j < grafo[u].size(); ++j) {
				int v = grafo[u][j];
				if (v != parent[u])
					pres += DP(v, i);
			}
			res = min(res, pres);
		}
	}
	return memo[u][pe] = res;
}

void Enraizar(int u = 1, int p = 0) {
	if (p)
		parent[u] = p;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v != p)
			Enraizar(v, u);
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXE; ++j)
			memo[i][j] = -1;
	
	cin >> N >> E;
	
	for (int i = 1; i <= E; ++i)
		for (int j = 1; j <= E; ++j)
			cin >> Mcost[i][j];
	
	for (int i = 1; i <= E; ++i) {
		int mn;
		cin >> mn;
		for (int j = 0; j < mn; ++j) {
			int u;
			cin >> u;
			FX[u] = i;
		}
	}
	
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	
	Enraizar();
	
	int ans = 100000000;
	
	if (FX[1]) {
		int pans = 0;
		for (int i = 0; i < grafo[1].size(); ++i)
			pans += DP(grafo[1][i], FX[1]);
		ans = min(ans, pans);
	} else {
		for (int i = 1; i <= E; ++i) {
			int pans = 0;
			for (int j = 0; j < grafo[1].size(); ++j)
				pans += DP(grafo[1][j], i);
			ans = min(pans, ans);
		}
	}
	cout << ans << '\n';
	return 0;
}