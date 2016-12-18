#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000009;
const int MINF = -1000009;
const int INF = 1000009;

typedef pair<int, int> pii;
pii st[MAXN << 2];
int N, M, C;

void build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		st[n] = pii(MINF, INF);
		return;
	}
	int lc = (n << 1), rc = lc + 1, m = (l + r) >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	st[n].first = max(st[lc].first, st[rc].first);
	st[n].second = min(st[lc].second, st[rc].second);
}

void Update(int L, int R, int val, int n = 1, int l = 1, int r = N) {
	if (L > r || R < l) return;
	if (l == r) {
		st[n] = pii(val, val);
		return;
	}
	int lc = (n << 1), rc = lc + 1, m = (l + r) >> 1;
	Update(L, R, val, lc, l, m);
	Update(L, R, val, rc, m + 1, r);
	st[n].first = max(st[lc].first, st[rc].first);
	st[n].second = min(st[lc].second, st[rc].second);
}

pii Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if (l > R || r < L) return pii(MINF, INF);
	if ((r <= R) && (l >= L)) {
		return st[n];
	}
	int lc = (n << 1), rc = lc + 1, m = (l + r) >> 1;
	pii axu = Query(L, R, lc, l, m);
	pii axd = Query(L, R, rc, m + 1, r);
	pii ans;
	ans.first = max(axu.first, axd.first);
	ans.second = min(axu.second, axd.second);
	return ans;
}

int main() {
	scanf("%d%d%d",&N, &M, &C);
	int aux;
	build();
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &aux);
		Update(i, i, aux);
	}
	pii ans;
	for (int i = 1; i <= N; ++i) {
		int ni = i + M - 1;
		if (ni > N) break;
		ans = Query(i, ni); 
		if (ans.first - ans.second <= C)
			printf("%d\n", i);
	}
	return 0;
}