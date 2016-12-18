#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;
typedef pair<int, long long> pil;
vector<pil> grafo[MAXN];
//LCA
const int LOGV = 17;
int P[MAXN][LOGV];
int level[MAXN], parent[MAXN];
long long dista[MAXN];

void enraizar(int u = 0, int p = -1, int lvl = 0, long long dst = 0) {
	level[u] = lvl;
	dista[u] = dst;
	parent[u] = p;
	if (p == -1)
		parent[u] = 0;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i].first;
		long long c = grafo[u][i].second;
		if (v != p)
			enraizar(v, u, lvl + 1, dst + c);
	}
	return;
}

void Pre(int N) {
	for (int u = 1; u <= N; ++u) 
		P[u][0] = parent[u];
	for (int i = 1; (1 << i) <= N; ++i)
		for (int u = 1; u <= N; ++u)
			P[u][i] = P[P[u][i - 1]][i - 1];
}

int LCA(int p, int q) {
	if (level[p] < level[q])
		swap(p, q);
	int lg;
	for (lg = 1; (1 << lg) <= level[p]; ++lg);
	lg--;
	for (int i = lg; i >= 0; --i) {
		if (level[p] - (1 << i) >= level[q]) {
			p = P[p][i];
		}
	}
	if (p == q) return p;
	
	for (int i = lg; i >= 0; --i) {
		if (P[p][i] != - 1 && P[p][i] != P[q][i]) {
			p = P[p][i];
			q = P[q][i];
		}
	}
	return P[p][0];
}

void Limpia(int N) {
	for (int i = 0; i <= N; ++i) {
		grafo[i].clear();
		parent[i] = i;
		level[i] = 1;
		dista[i] = 0;
	}
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, Q;
	while (cin >> N) {
		if (!N) 
			break;
		Limpia(N);
		int A;
		long long L;
		for (int i = 1; i < N; ++i) {
			cin >> A >> L;
			grafo[i].push_back(pil(A, L));
			grafo[A].push_back(pil(i, L));
		}
		enraizar();
		Pre(N);
		cin >> Q;
		int a, b, lca;
		long long ans;
		for (int i = 0; i < Q; ++i) {
			if (i) 
				cout << ' ';
			cin >> a >> b;
			int lca = LCA(a, b);
			ans = dista[a] + dista[b] - (dista[lca] << 1);
			cout << ans;
		}
		cout << '\n';
	}
	return 0;
}