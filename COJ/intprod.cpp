#include <bits/stdc++.h>
using namespace std;

const int MAXN = 900000;

int ST[MAXN * 3], arr[MAXN], N, Q;

void build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		ST[n] = arr[n];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	build(ls, l, m); 
	build(rs, m + 1, r);
	ST[n] = ST[ls] * ST[rs];
}

int Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if (r < L || l > R) return 1;
	if ((L <= l) && (r <= R)) {
		return ST[n];
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	return Query(L, R, ls, l, m) * Query(L, R, rs, m + 1, r);
}

void Update(int at, int val, int n = 1, int l = 1, int r = N) {
	if ((at < l) || (at > r)) return;
	if (l == r) {
		ST[n] = val;
		return;
	}
	// cout << l << ' ' << r  << '\n';
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Update(at, val, ls, l, m);
	Update(at, val, rs, m + 1, r);
	ST[n] = ST[ls] * ST[rs];	
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	while(cin >> N >> Q) {
		for (int i = 0; i < N; ++i) {
			int ai;
			cin >> ai;
			if (ai > 0) ai = 1;
			if (ai < 0) ai = -1;
			Update(i + 1, ai);
		}
		for (int i = 0; i < Q; ++i) {
			char opc;
			int u, v;
			cin >> opc >> u >> v;
			if (opc == 'C') {
				if (v > 0) v = 1;
				if (v < 0) v = -1;
				Update(u, v);
			} else {
				char val = '0';
				int res = Query(u, v);
				if (res > 0) val = '+';
				if (res < 0) val = '-';
				cout << val;
			}
		}
		cout << '\n';
	}

	return 0;
}