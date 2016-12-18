#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30100;
const int INF = 1000000009;
const int MAXK = 15;

int N, q;
int nv[MAXN];
int st[MAXN * 3], barray[MAXN]; //segtree, base array
int g[MAXN], p[MAXN][MAXK], d[MAXN], ix[MAXN], sz[MAXN], nIx; 
//head of the list of the node, parent, level, index in base array, subsize, current index (basearray)
vector < int > grafo[MAXN];

int query(int i, int j, int n = 0, int l = 0, int r = N - 1) {
	if (j < l || r < i) return 0;
	if (i <= l && r <= j) return st[n];
	int lc = (n << 1) + 1, m = (l + r) >> 1;
	return query(i, j, lc, l, m) +
	             query(i, j, lc + 1, m + 1, r);
}

void build(int n = 0, int l = 0, int r = N - 1) {
	if (l == r) {
		st[n] = barray[l];
		return;
	}
	int lc = (n << 1) + 1, m = (l + r) >> 1;
	build(lc, l, m);
	build(lc + 1, m + 1, r);
	st[n] = st[lc] + st[lc + 1];
}

void update(int i, int x, int n = 0, int l = 0, int r = N - 1) {
	if (i < l || i > r) return;
	if (l == r){
		st[n] = x;
		return;
	}
	int lc = (n << 1) + 1, m = (l + r) >> 1;
	update(i, x, lc, l, m);
	update(i, x, lc + 1, m + 1, r);
	st[n] = st[lc] + st[lc + 1];
}

int LCA(int u, int v) {
	if (d[u] < d[v])
		swap(u, v);

	for (int i = MAXK - 1; i >= 0; --i)
		if (d[p[u][i]] >= d[v])
			u = p[u][i];

	if (u == v) return u;

	for (int i = MAXK - 1; i >= 0; --i)
		if (p[u][i] != p[v][i]){
			u = p[u][i];
			v = p[v][i];
		}

	return p[u][0];
}

int size(int n, int pr) {
	sz[n] = 1;
	int lim = grafo[n].size();
	for (int i = 0; i < lim; ++i) {
		int v = grafo[n][i];
		if (v == pr) continue;
		sz[n] += size(v, n);
	}
	return sz[n];
}

void hl(int n, int pr, int grp){
	int best = -1;

	d[n] = (n ? d[pr] : 0) + 1;
	p[n][0] = pr;
	g[n] = grp;
	barray[nIx] = nv[n]; 
	ix[n] = nIx;
	nIx++;
	
	int lim = grafo[n].size();
	for (int i = 0; i < lim; ++i) {
		int v = grafo[n][i];
		if (v == pr) continue;
		if (best == -1 || sz[best] < sz[v])
			best = v;
	}

	if (best != -1)
		hl(best, n, grp);

	for (int i = 0; i < lim; ++i) {
		int v = grafo[n][i];
		if (v == pr || v == best) continue;
		hl(v, n, v);
	}
}

int lineQ(int u, int v){
	int ans = 0;

	for (; g[u] != g[v]; u = p[g[u]][0])
		ans += query(ix[g[u]], ix[u]);

	ans += query(ix[v], ix[u]);

	return ans;
}

int treeQ(int u, int v) {
	int l = LCA(u, v);
	return lineQ(u, l) + lineQ(v, l) - lineQ(l, l);
}

void PreLCA() {
	for (int k = 1; k < MAXK; ++k)
		for (int i = 0; i < N; ++i)
			p[i][k] = p[p[i][k - 1]][k - 1];
	return;
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	//cin >> T;
	scanf("%d", &T);
	for (int nc = 1; nc <= T; ++nc) {
		
		//cin >> N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &nv[i]);
			//cin >> nv[i];
			grafo[i].clear();
		}
		nIx = 0;
		int lim = N - 1, u, v;
		for (int i = 0; i < lim; ++i) {
			scanf("%d%d", &u, &v);
			//cin >> u >> v;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		
		size(0, 0);
		hl(0, 0, 0);
		build();
		PreLCA();
		
		//cout << "Case " << nc << ":\n";
		printf("Case %d:\n", nc);
		scanf("%d", &q);
		//cin >> q;
		int op;
		while (q--) {
			scanf("%d%d%d", &op, &u, &v);
			//cin >> op >> u >> v;
			if (op)
				update(ix[u], v);
			else
				printf("%d\n", treeQ(u, v));
				//cout << treeQ(u, v) << '\n';
		}
	}
	return 0;
}