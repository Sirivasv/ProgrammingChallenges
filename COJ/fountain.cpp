#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

lli ST[MAXN * 4], Lazy[MAXN * 4];
int N;
lli arr[MAXN];

void Build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		ST[n] = arr[l];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = ST[ls] + ST[rs];
}

void Update(int L, int R, lli v, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L)) 
		return;
	
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	
	if (Lazy[n] && (l != r)) {
		ST[ls] = 0;
		ST[rs] = 0;
		Lazy[ls] = 1;
		Lazy[rs] = 1;
		Lazy[n] = 0;
	}
	
	if ((l >= L) && (r <= R)) {
		ST[n] = v;
		Lazy[n] = 1;
		return;
	}
	
	Update(L, R, v, ls, l, m);
	Update(L, R, v, rs, m + 1, r);
	ST[n] = ST[ls] + ST[rs];
}

lli Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L)) 
		return 0;
	
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	
	if (Lazy[n] && (l != r)) {
		ST[ls] = 0;
		ST[rs] = 0;
		Lazy[ls] = 1;
		Lazy[rs] = 1;
		Lazy[n] = 0;
	}
	
	if ((l >= L) && (r <= R))
		return ST[n];
	
	return (Query(L, R, ls, l, m) + Query(L, R, rs, m + 1, r));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	Build();
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int tp, I;
		lli J;
		cin >> tp;
		if (tp == 2) {
			cin >> I >> J;
			int ini = I, fin = N, ans = -1;
			
			while (ini <= fin) {
				int m = (ini + fin) >> 1;
				if (Query(I, m) >= J) {
					ans = m;
					fin = m - 1;
				} else
					ini = m + 1;
			}
			
			if (ans == -1) {
				Update(I, N, 0);
			} else {
				lli preval = Query(I, ans);
				Update(I, ans, 0);
				lli nv = max(0LL, preval - J);
				Update(ans, ans, nv);
			}
		} else {
			cin >> I;
			cout << (arr[I] - Query(I, I)) << '\n';
		}
	}
	return 0;
}