#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;

int st[MAXN << 2], lazy[MAXN << 2];

int tini[MAXN], tend[MAXN];
vector<int> grafo[MAXN];

int N, M;

int TDFS(int Ts, int p, int u) {
	tini[u] = Ts;
	int t = Ts;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v == p) continue;
		t = TDFS(t + 1, u, v);
	}
	tend[u] = t;
	return t;
}

void Update(int L, int R, int val, int n = 1, int l = 1, int r = N) {
	if (l > R || r < L) return;
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	if (lazy[n] && (l != r)) {
		lazy[lc] = lazy[n];
		lazy[rc] = lazy[n];
		st[lc] = lazy[n];
		st[rc] = lazy[n];
		lazy[n] = 0;
	}
	if (l >= L && r <= R) {
		lazy[n] = val;
		st[n] = val;
		return;
	}
	Update(L, R, val, lc, l, m);
	Update(L, R, val, rc, m + 1, r);
    //st[n] =  
}

int Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if (l > R || r < L) return 0;
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	if (lazy[n] && (l != r)) {
		lazy[lc] = lazy[n];
		lazy[rc] = lazy[n];
		st[lc] = lazy[n];
		st[rc] = lazy[n];
		lazy[n] = 0;
	}
	if (l >= L && r <= R) return st[n];
	return Query(L, R, lc, l, m) + Query(L, R, rc, m + 1, r);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	int p, root;
	for (int i = 1; i <= N; ++i) {
		cin >> p;
		if (!p) { 
			root = i;
			continue;
		}
		grafo[i].push_back(p);
		grafo[p].push_back(i);
	}
	TDFS(1, -1, root);
	int x, c;
	for (int i = 0; i < M; ++i) {
		cin >> x >> c;
		Update(tini[x], tend[x], c);
	}
	set<int> mys;
	for (int i = 1; i <= N; ++i) {
		int val = Query(i, i);
		if (val)
			mys.insert(val);
	}
	cout << mys.size() << '\n';
	return 0;
}