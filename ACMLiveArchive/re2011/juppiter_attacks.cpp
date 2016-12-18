#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;

int N, Q;
long long B, P;
long long potB[MAXN], invpotB[MAXN];

long long st[MAXN * 3]; 

long long InvMod(long long x) {
	long long res = 1LL, p = x;
	for (long long n = P - 2LL; n; n >>= 1) {
		if (n & 1) 
			res = (res * p) % P;
		p = (p * p) % P;
	}
	return res;
}

void PreCalc() {
	potB[0] = 1LL;
	invpotB[0] = InvMod(potB[0]);
	for (int i = 1; i < N; ++i) {
		potB[i] = (potB[i - 1] * B) % P;
		invpotB[i] = InvMod(potB[i]);
	}
	return;
}

void update(int ID, long long val, int n = 1, int l = 1, int r = N) {
	if (l > ID || r < ID)
		return;
	if (l == r) {
		st[n] = (val * potB[N - l]) % P;
		return;
	}
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	update(ID, val, lc, l, m);
	update(ID, val, rc, m + 1, r);
	st[n] = (st[lc] + st[rc]) % P;
	return;
}

long long Query(int L, int R, int n = 1, int l = 1, int r = N) {
	
	if (l > R || r < L)
		return 0LL;
	if (l >= L && r <= R)
		return st[n];
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	long long la = Query(L, R, lc, l, m);
	long long ra = Query(L, R, rc, m + 1, r);
	la = (la + ra) % P;
	return la;
}


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> B >> P >> N >> Q) {
		if (!(B + P + (long long)N + (long long)Q))
			break;
		
		PreCalc();
		
		for (int i = 1; i <= N; ++i)
			update(i, 0LL);
		
		char opc;
		int u;
		long long v, ans;
		for (int i = 0; i < Q; ++i) {
			cin >> opc >> u >> v;
			if (opc == 'E') {
				update(u, v);
			}
			else {
				ans = Query(u, (int)v);
				ans = (ans * invpotB[N - (int)v]) % P;
				cout << ans << '\n';
			}
		}
		cout << "-\n";
	}
	return 0;
}
