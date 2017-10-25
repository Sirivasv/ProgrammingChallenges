#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<int, lli> pil;

const int MAXN = 100009;
const int LOGV = 18;

vector<pil> grafo[MAXN];
lli dist[MAXN];

int N, Q, P[MAXN][LOGV], level[MAXN];

void PRE() {
	for (int d = 1; d < LOGV; ++d)
		for (int i = 0; i < N; ++i)
			P[i][d] = P[P[i][d - 1]][d - 1];
}

int LCA(int u, int v) {
	if (level[u] > level[v]) swap(u, v);
	for (int i = 0, j = level[v] - level[u]; i < LOGV && j > 0; ++i, j >>= 1)
		if (j & 1) v = P[v][i];
	if (u == v) return u;
	for (int i = LOGV - 1; i >= 0; --i)
		if (P[u][i] != P[v][i]) {
			u = P[u][i];
			v = P[v][i];
		}
	return P[u][0];
}

void PDFS (int u, int par, lli pes, int lev) {
	dist[u] = pes;
	level[u] = lev;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i].first;
		lli p = grafo[u][i].second;
		if (v != par) {
			P[v][0] = u;
			PDFS(v, u, pes + p, lev + 1);
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N) {
		if (!N)
			break;
		for (int i = 0; i < N; ++i)
			grafo[i].clear();
		for (int i = 1; i < N; ++i) {
			int v;
			lli p;
			cin >> v >> p;
			grafo[i].push_back(pil(v, p));
			grafo[v].push_back(pil(i, p));
		}
		PDFS(0, -1, 0, 1);
		PRE();
		cin >> Q;
		for (int i = 0; i < Q; ++i) {
			int u, v;
			cin >> u >> v;
			if (i)
				cout << ' ';
			cout << (dist[u] + dist[v] - (2 * dist[LCA(u, v)]));
		}
		cout << '\n';
	}
	return 0;
}