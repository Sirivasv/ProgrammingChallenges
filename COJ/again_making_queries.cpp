#include <bits/stdc++.h>
using namespace std;
const long long MOD = 10000;
const int MAXN = 10000000;
int N, Q, U, a, b;
long long v;
long long ST[MAXN * 3];

inline void update(int n, int L, int R, int a, long long val) {
	int b = a;
	if (b < L || a > R) return; 
	if (L >= a && R <= b) {
		ST[n] += val;
		return;
	}
	int lc = n << 1, mid = (L + R) >> 1;
	update(lc, L, mid, a, val);
	update(lc + 1, mid + 1, R, a, val);
	ST[n] = ST[lc] + ST[lc + 1];
	return;
}

inline long long Query(int n, int L, int R, int l, int r) {
	if ((l > R) || (r < L)) return 0;
	if (L >= l && R <= r) return ST[n];
	int lc = n << 1, mid = (L + R) >> 1;
	return Query(lc, L, mid, l, r) + Query(lc + 1, mid + 1, R, l, r);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> U >> Q; 
	for (int i = 0; i < U; i++) {
		cin >> a >> v;
		if(a > 1) update(1, 1, N, a - 1, v);
		update(1, 1, N, a, v + 1LL);
		if(a < N) update(1, 1, N, a + 1, v);
	}
	
	for (int i = 0; i < Q; i++) {
		cin >> a >> b;
		cout << Query(1, 1, N, a, b) % MOD << '\n';
	}
	return 0;	
}