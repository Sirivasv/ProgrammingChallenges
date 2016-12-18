#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500009;

typedef long long lli;

lli ST[MAXN], Lazy[MAXN], arr[MAXN], N;

void Build(int n = 1, int L = 1, int R = N) {
	
	if (L == R) {
		ST[n] = arr[L];
		return;
	}
	
	int ls = (n << 1), rs = ls + 1, m = (L + R) >> 1;
	
	Build(ls, L, m);
	Build(rs, m + 1, R);
	ST[n] = max(ST[ls], ST[rs]);
}

void Update(int r, lli v, int l = 1, int n = 1, int L = 1, int R = N) {
	if ((L > r) || (R < l))
		return;
	
	int ls = (n << 1), rs = ls + 1, m = (L + R) >> 1;
	
	if (Lazy[n] && (L != R)) {
		ST[ls] = Lazy[n];
		ST[rs] = Lazy[n];
		Lazy[ls] = Lazy[n];
		Lazy[rs] = Lazy[n];
		Lazy[n] = 0;
	}
	
	if ((L >= l) && (R <= r)) {
		ST[n] = v;
		Lazy[n] = v;
		return;
	}
	
	Update(r, v, l, ls, L, m);
	Update(r, v, l, rs, m + 1, R);
	ST[n] = max(ST[ls], ST[rs]);
}

lli Query(int l, int r, int n = 1, int L = 1, int R = N) {
	if ((L > r) || (R < l))
		return -1LL;
	
	int ls = (n << 1), rs = ls + 1, m = (L + R) >> 1;
	
	if (Lazy[n] && (L != R)) {
		ST[ls] = Lazy[n];
		ST[rs] = Lazy[n];
		Lazy[ls] = Lazy[n];
		Lazy[rs] = Lazy[n];
		Lazy[n] = 0;
	}
	
	if ((L >= l) && (R <= r))
		return ST[n];
	
	return max(Query(l, r, ls, L, m), Query(l, r, rs, m + 1, R));
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
		int I, J;
		cin >> I >> J;
		cout << Query(1, I) << '\n';
		Update(I, (Query(1, I) + J));
	}
	return 0;
}