#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
int N, M;
int tini[MAXN], tend[MAXN]; 

vector<int> grafo[MAXN];

long long st[MAXN << 2], lazy[MAXN << 2], arr[MAXN];

int TDFS(int Ts, int p, int u) {
	tini[u] = Ts;
	int t = Ts;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v == p) continue;
		t = TDFS(t + 1, u, v);
	}
	return tend[u] = t;
}

void build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		st[n] = lazy[l];
		return;
	}
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	return;
}

void Update(int L, int R, long long val, int n = 1, int l = 1, int r = N) {
	if (l > R || r < L) return;
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	if (lazy[n] && (l != r)) {
		lazy[lc] += lazy[n];
		lazy[rc] += lazy[n];
		st[lc] += lazy[n];
		st[rc] += lazy[n];
		lazy[n] = 0;
	}
	if (l >= L && r <= R) {
		lazy[n] += val;
		st[n] += val;
		return;
	}
	Update(L, R, val, lc, l, m);
	Update(L, R, val, rc, m + 1, r);
	return;
}

long long Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if (l > R || r < L) return 0;
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	if (lazy[n] && (l != r)) {
		lazy[lc] += lazy[n];
		lazy[rc] += lazy[n];
		st[lc] += lazy[n];
		st[rc] += lazy[n];
		lazy[n] = 0;
	}
	if (l >= L && r <= R) return st[n];
	return Query(L, R, lc, l, m) + Query(L, R, rc, m + 1, r);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	cin >> arr[1];
	int p;
	for (int i = 2; i <= N; ++i) {
		cin >> arr[i] >> p;
		grafo[p].push_back(i);
		grafo[i].push_back(p);
	}
	TDFS(1, -1, 1);
	for (int i = 1; i <= N; ++i)
		lazy[tini[i]] = arr[i];
	build();
	for (int i = 1; i <= N; ++i)
		lazy[tini[i]] = 0;
	string s;
	int u;
	long long v;
	while(M--) {
		cin >> s >> u;
		if (s[0] == 'C') {
			cin >> v;
			Update(tini[u], tend[u], v);
			Update(tini[u], tini[u], -v);
		} else {
			cout << Query(tini[u], tini[u]) << '\n';
		}
	}
	return 0;
}