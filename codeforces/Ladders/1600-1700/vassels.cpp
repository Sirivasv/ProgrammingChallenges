#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200009;

int N;
lli ST[MAXN * 3], Lazy[MAXN * 3], arr[MAXN];

void Build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		ST[n] = arr[l];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = ST[ls] + ST[rs];
}

lli Query(int L , int R, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L)) return 0;
	
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	if ((l != r) && Lazy[n]) {
		ST[ls] = ST[rs] = 0;
		Lazy[ls] = Lazy[rs] = 1;
		Lazy[n] = 0;
	}
	
	if ((l >= L) && (r <= R)) return ST[n];
	
	return Query(L, R, ls, l, m) + Query(L, R, rs, m + 1, r);
}

void Update(int L, int R, lli val, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L)) return;
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	if ((l != r) && Lazy[n]) {
		ST[ls] = ST[rs] = 0;
		Lazy[ls] = Lazy[rs] = 1;
		Lazy[n] = 0;
	}
	if ((l >= L) && (r <= R)) {
		ST[n] = val;
		Lazy[n] = 1;
		return;
	}
	Update(L, R, val, ls, l, m);
	Update(L, R, val, rs, m + 1, r);
	ST[n] = ST[ls] + ST[rs];
}

void UpdateQ(int I, lli J) {
	int ini = I, fin = N, ans = -1;
	while (ini <= fin) {
		int m = (ini + fin) / 2;
		if (Query(I, m) >= J) {
			ans = m;
			fin = m - 1;
		} else ini = m + 1;
	}
	if (ans == -1) Update(I, N, 0);
	else {
		lli prev = Query(I, ans);
		Update(I, ans, 0);
		Update(ans, ans, prev - J);
	}
}

int main() {
	
	scanf("%d", &N);
	
	for (int i = 1; i <= N; ++i) scanf("%lld", &arr[i]);
	
	Build();
	
	int Q;
	scanf("%d", &Q);
	
	for (int i = 0; i < Q; ++i) {
		int tp, I;
		lli J;
		scanf("%d%d", &tp, &I);
		if (tp == 1) {
			scanf("%lld", &J);
			UpdateQ(I, J);
		} else printf("%lld\n", arr[I] - Query(I, I));
	}
	
	return 0;
}