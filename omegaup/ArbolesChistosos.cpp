#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200009;
vector<int> grafo[MAXN];
int par[MAXN << 2], impar[MAXN << 2], tini[MAXN], tend[MAXN];
int Lazyp[MAXN << 2], Lazyimp[MAXN << 2];
bitset<MAXN> parity;
int N, M;

int TDFS(int Tini, int p, int u, int par) {
	tini[u] = Tini;
	int t = Tini;
	if (par) parity[u] = 1;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v == p) continue;
		t = TDFS(t + 1, u, v, (par + 1) % 2);
	}
	tend[u] = t;
	return t;
}

void build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		par[n] = Lazyimp[l];
		impar[n] = Lazyimp[l];
		return;
	} 
	int lc = (n << 1), rc = lc + 1, m = (l + r) >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	par[n] = par[lc] + par[rc]; 
	impar[n] = impar[lc] + impar[rc];
	return;
}

void UpdateImPar(int L, int R, int val, int n = 1, int l = 1, int r = N) {
	if (L > r || l > R) return;
	int lc = (n << 1), rc = lc + 1, m = (l + r) >> 1;
	if (Lazyimp[n] && l != r) {
		Lazyimp[lc] += Lazyimp[n];
		Lazyimp[rc] += Lazyimp[n];
		impar[lc] += Lazyimp[n];
		impar[rc] += Lazyimp[n];
		Lazyimp[n] = 0;
	}
	if (l >= L && r <= R) {
		Lazyimp[n] += val;
		impar[n] += val;
		return;
	}
	UpdateImPar(L, R, val, lc, l, m);
	UpdateImPar(L, R, val, rc, m + 1, r);
	impar[n] = impar[lc] + impar[rc];
	return;
}

void UpdatePar(int L, int R, int val, int n = 1, int l = 1, int r = N) {
	if (L > r || l > R) return;
	int lc = (n << 1), rc = lc + 1, m = (l + r) >> 1;
	if (Lazyp[n] && l != r) {
		Lazyp[lc] += Lazyp[n];
		Lazyp[rc] += Lazyp[n];
		par[lc] += Lazyp[n];
		par[rc] += Lazyp[n];
		Lazyp[n] = 0;
	}
	if (l >= L && r <= R) {
		Lazyp[n] += val;
		par[n] += val;
		return;
	}
	UpdatePar(L, R, val, lc, l, m);
	UpdatePar(L, R, val, rc, m + 1, r);
	par[n] = par[lc] + par[rc];
	return;
}

int QueryPar(int L, int R, int n = 1, int l = 1, int r = N) {
	if (L > r || l > R) return 0;
	int lc = (n << 1), rc = lc + 1, m = (l + r) >> 1;
	if (Lazyp[n] && l != r) {
		Lazyp[lc] += Lazyp[n];
		Lazyp[rc] += Lazyp[n];
		par[lc] += Lazyp[n];
		par[rc] += Lazyp[n];
		Lazyp[n] = 0;
	}
	if (l >= L && r <= R) return par[n];
	int v1 = QueryPar(L, R, lc, l, m);
	int v2 = QueryPar(L, R, rc, m + 1, r);
	return v1 + v2; 
}

int QueryImPar(int L, int R, int n = 1, int l = 1, int r = N) {
	if (L > r || l > R) return 0;
	int lc = (n << 1), rc = lc + 1, m = (l + r) >> 1;
	if (Lazyimp[n] && l != r) {
		Lazyimp[lc] += Lazyimp[n];
		Lazyimp[rc] += Lazyimp[n];
		impar[lc] += Lazyimp[n];
		impar[rc] += Lazyimp[n];
		Lazyimp[n] = 0;
	}
	if (l >= L && r <= R) return impar[n];
	int v1 = QueryImPar(L, R, lc, l, m);
	int v2 = QueryImPar(L, R, rc, m + 1, r);
	return v1 + v2; 
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> Lazyp[i];
	int u, v;
	for (int i = 0; i < N - 1; ++i) {
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	TDFS(1, -1, 1, 0);
	for (int i = 1; i <= N; ++i) 
		Lazyimp[tini[i]] = Lazyp[i];
	build();
	for (int i = 0; i <= N; ++i) 
		Lazyimp[i] = Lazyp[i] = 0;
	int tq;
	while (M--) {
		cin >> tq >> u;
		if (tq == 1) {
			cin >> v;
			if (parity[u]) {
				UpdatePar(tini[u], tend[u], v);
				UpdateImPar(tini[u], tend[u], -v);
			} else {
				UpdatePar(tini[u], tend[u], -v);
				UpdateImPar(tini[u], tend[u], v);
			}
		} else {
			if (parity[u])
				cout << QueryPar(tini[u], tini[u]) << '\n';
			else
				cout << QueryImPar(tini[u], tini[u]) << '\n';
		}
	}
	return 0;
}