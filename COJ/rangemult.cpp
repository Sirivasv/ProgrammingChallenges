#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1000000009LL;
const int MAXN = 1000009;


lli ST[MAXN * 3], Lazy[MAXN * 3];
int N, M;

void Build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		Lazy[n] = -1LL;
		ST[n] = 1LL;
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = (ST[ls] + ST[rs]) % MOD;
	Lazy[n] = -1LL;
}

void Update(int L, int R, lli k, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L))
		return;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	if ((Lazy[n] != -1LL) && (l != r)) {
		ST[ls] = (ST[ls] * Lazy[n]) % MOD;
		ST[rs] = (ST[rs] * Lazy[n]) % MOD;
		
		if (Lazy[ls] == -1LL)
			Lazy[ls] = Lazy[n];
		else 
			Lazy[ls] = (Lazy[ls] * Lazy[n]) % MOD;
		
		if (Lazy[rs] == -1LL)
			Lazy[rs] = Lazy[n];
		else 
			Lazy[rs] = (Lazy[rs] * Lazy[n]) % MOD;
		Lazy[n] = -1LL;
	}
	if ((l >= L) && (r <= R)) {
		ST[n] = (ST[n] * k) % MOD;
		if (Lazy[n] == -1LL)
			Lazy[n] = k;
		else 
			Lazy[n] = (Lazy[n] * k) % MOD;
		return;
	}
	Update(L, R, k, ls, l, m);
	Update(L, R, k, rs, m + 1, r);
	ST[n] = (ST[ls] + ST[rs]) % MOD;
}
 
lli Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L))
		return 0;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	if ((Lazy[n] != -1LL) && (l != r)) {
		ST[ls] = (ST[ls] * Lazy[n]) % MOD;
		ST[rs] = (ST[rs] * Lazy[n]) % MOD;
		
		if (Lazy[ls] == -1LL)
			Lazy[ls] = Lazy[n];
		else 
			Lazy[ls] = (Lazy[ls] * Lazy[n]) % MOD;
		
		if (Lazy[rs] == -1LL)
			Lazy[rs] = Lazy[n];
		else 
			Lazy[rs] = (Lazy[rs] * Lazy[n]) % MOD;
		Lazy[n] = -1LL;
	}
	
	if ((l >= L) && (r <= R))
		return ST[n];
	
	return ((Query(L, R, ls, l, m) + Query(L, R, rs, m + 1, r)) % MOD);
}
 
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N >> M) {
		Build();
		for (int i = 0; i < M; ++i) {
			int tp;
			cin >> tp;
			if (tp == 1) {
				int I, J;
				cin >> I >> J;
				cout << Query(I, J) << '\n';
			} else {
				int I, J;
				lli K;
				cin >> I >> J >> K;
				Update(I, J, K);
			}
		}
	}
	return 0;
}