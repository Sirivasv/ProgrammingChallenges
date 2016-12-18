#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 2009;
const lli MOD = 1000000007LL;

vector<int> grafo[MAXN];

int D, N, cst[MAXN], root;

lli DFS(int u, int val, int p) {
	lli many = 1LL;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if ((cst[v] >= val) && (v != p) && ((cst[v] - val) <= D) && (!((val == cst[v]) && (v < root))))
			many =  (many * (DFS(v, val, u) + 1LL)) % MOD;
	}
	return many;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> D >> N;
	for (int i = 0; i < N; ++i)
		cin >> cst[i];
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	lli ans = 0;
	for (int i = 0; i < N; ++i) {
		root = i;
		ans = (ans + DFS(i, cst[i], -1)) % MOD;
	}
	cout << ans << '\n';
	return 0;
}