#include <bits/stdc++.h>
using namespace std;
//HLD de nodos indexado desde 0, Lazy
const int MAXN = 100009;
const int MAXK = 17;

int N, q;
int wst[MAXN * 3], Lazy[MAXN * 3];
int g[MAXN], p[MAXN][MAXK], d[MAXN], ix[MAXN], sz[MAXN], nIx; 
vector < int > grafo[MAXN];

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

int query(int i, int j, int n = 0, int l = 0, int r = N - 1) {
	if (j < l || r < i) return 0;
	
	int lc = (n << 1) + 1, rc = lc + 1, size = r - l + 1, m = (l + r) >> 1;
	if ((Lazy[n]) && (l != r)) {
		int sizel = (m - l + 1), sizer = (r - m);
		wst[lc] = sizel - wst[lc];
		Lazy[lc]++;
		Lazy[lc] %= 2;
		wst[rc] = sizer - wst[rc];	
		Lazy[rc]++;
		Lazy[rc] %= 2;
		Lazy[n] = 0;
	}
	if (i <= l && r <= j) return wst[n];
	
	return query(i, j, lc, l, m) +
	             query(i, j, rc, m + 1, r);
}

void build(int n = 0, int l = 0, int r = N - 1) {
	if (l == r) {
		wst[n] = 1;
		return;
	}
	int lc = (n << 1) + 1, m = (l + r) >> 1;
	build(lc, l, m);
	build(lc + 1, m + 1, r);
	wst[n] = wst[lc] + wst[lc + 1];
}

void update(int i, int j, int n = 0, int l = 0, int r = N - 1) {
	if (j < l || i > r) return;
	int lc = (n << 1) + 1, rc = lc + 1, size = r - l + 1, m = (l + r) >> 1;
	if ((Lazy[n]) && (l != r)) {
		int sizel = (m - l + 1), sizer = (r - m);
		wst[lc] = sizel - wst[lc];
		wst[rc] = sizer - wst[rc];	
		Lazy[lc]++;
		Lazy[lc] %= 2;
		Lazy[rc]++;
		Lazy[rc] %= 2;
		Lazy[n] = 0;
	}
	
	if (i <= l && r <= j) {
		Lazy[n]++;
		Lazy[n] %= 2;
		wst[n] = size - wst[n];
		return;
	}
	update(i, j, lc, l, m);
	update(i, j, rc, m + 1, r);
	wst[n] = wst[lc] + wst[rc];
}

void lineU(int u, int v){
	for (; g[u] != g[v]; u = p[g[u]][0])
		update(ix[g[u]], ix[u]);
	update(ix[v], ix[u]);
	return;
}

void updatetree(int u, int v) {
	int l = LCA(u, v);
	//be careful with the next lines, this problem allowed this type of
	//updates, others may not
	lineU(u, l);
	lineU(v, l);
	lineU(l, l);
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
	//barray[nIx] = nv[n]; 
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
	scanf("%d", &N);
	nIx = 0;
	int lim = N - 1, u, v;
	for (int i = 0; i < lim; ++i) {
		scanf("%d%d", &u, &v);
		u--, v--;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	
	size(0, 0);
	hl(0, 0, 0);
	build();
	PreLCA();
	scanf("%d", &q);
	int op;
	while (q--) {
		scanf("%d%d%d", &op, &u, &v);
		u--, v--;
		if (op == 1)
			updatetree(u, v);
		else
			printf("%d\n", treeQ(u, v));
	}
	return 0;
}