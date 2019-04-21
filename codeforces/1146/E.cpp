#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200009;

lli ST[MAXN * 3], Lazy[MAXN * 3];
lli arr[MAXN];
int N;

void Build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		Lazy[n] = 0;
		ST[n] = 1LL;
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = (ST[ls] + ST[rs]);
	Lazy[n] = 0;
}

void Update(int L, int R, lli k, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L))
		return;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	if ((Lazy[n] != 0) && (l != r)) {
		ST[ls] = ST[ls] * Lazy[n];
		ST[rs] = ST[rs] * Lazy[n];
		
		if (Lazy[ls] == 0)
			Lazy[ls] = Lazy[n];
		else 
			Lazy[ls] = Lazy[ls] * Lazy[n];
		
		if (Lazy[rs] == 0)
			Lazy[rs] = Lazy[n];
		else 
			Lazy[rs] = Lazy[rs] * Lazy[n];
		Lazy[n] = 0;
	}
	if ((l >= L) && (r <= R)) {
		ST[n] = ST[n] * k;
		if (Lazy[n] == 0)
			Lazy[n] = k;
		else 
			Lazy[n] = Lazy[n] * k;
		return;
	}
	Update(L, R, k, ls, l, m);
	Update(L, R, k, rs, m + 1, r);
	ST[n] = (ST[ls] + ST[rs]);
}

lli Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L))
		return 0;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;

	if ((Lazy[n] != 0) && (l != r)) {
		ST[ls] = ST[ls] * Lazy[n];
		ST[rs] = ST[rs] * Lazy[n];
		
		if (Lazy[ls] == 0)
			Lazy[ls] = Lazy[n];
		else 
			Lazy[ls] = Lazy[ls] * Lazy[n];
		
		if (Lazy[rs] == 0)
			Lazy[rs] = Lazy[n];
		else 
			Lazy[rs] = Lazy[rs] * Lazy[n];
		Lazy[n] = 0;
	}
	
	if ((l >= L) && (r <= R)) return ST[n];
	
	return Query(L, R, ls, l, m) + Query(L, R, rs, m + 1, r);
}

int main() {

    cin.tie(0); ios_base::sync_with_stdio(0);
    int Q;
	cin >> N >> Q;

	for (int i = 1; i <= N; ++i) cin >> arr[i];
	Build(1, 1, 200005);

	for (int i = 0; i < Q; ++i) {
		char op;
		int xi;
		cin >> op >> xi;
		if (op == '>') {
			Update(xi + 1 + 100002, 200005, -1LL, 1, 1, 200005);
		} else {
			Update(1, xi - 1 + 100002, -1LL, 1, 1, 200005);
		}
	}

	for (int i = 1; i <= N; ++i) {
		lli res = arr[i] * Query(arr[i] + 100002, arr[i] + 100002, 1, 1, 200005);
		if (i > 1) cout << ' ';
		cout << res;
	}
	cout << '\n';

    return 0;
}