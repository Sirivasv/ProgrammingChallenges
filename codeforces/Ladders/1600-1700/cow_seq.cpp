#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200002;

lli ST[MAXN * 3], Lazy[MAXN * 3];
int tam;

void Set(int id, lli val, int n = 1, int l = 1, int r = MAXN - 1) {
	if ((l > id) || (r < id)) return;
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	if (Lazy[n] && (l != r)) {
		if (l <= tam) {
			ST[ls] += Lazy[n] * ((lli)(min(tam, m) - l + 1));
			Lazy[ls] += Lazy[n];
		}
		if ((m + 1) <= tam) {
			ST[rs] += Lazy[n] * ((lli)(min(tam, r) - (m + 1) + 1));
			Lazy[rs] += Lazy[n];
		}
		Lazy[n] = 0;
	}
	if (l == r) {
		ST[n] = val;
		return;
	}
	Set(id, val, ls, l, m);
	Set(id, val, rs, m + 1, r);
	ST[n] = ST[ls] + ST[rs];
}

lli Query(int L, int R, int n = 1, int l = 1, int r = MAXN - 1) {
	if ((l > R) || (r < L)) return 0;
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	if (Lazy[n] && (l != r)) {
		if (l <= tam) {
			ST[ls] += Lazy[n] * ((lli)(min(tam, m) - l + 1));
			Lazy[ls] += Lazy[n];
		}
		if ((m + 1) <= tam) {
			ST[rs] += Lazy[n] * ((lli)(min(tam, r) - (m + 1) + 1));
			Lazy[rs] += Lazy[n];
		}
		Lazy[n] = 0;
	}
	if ((L <= l) && (r <= R)) return ST[n]; 
	return Query(L, R, ls, l, m) + Query(L, R, rs, m + 1, r);
}

void Update(int L, int R, lli val, int n = 1, int l = 1, int r = MAXN - 1) {
	if ((l > R) || (r < L)) return;
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	if (Lazy[n] && (l != r)) {
		if (l <= tam) {
			ST[ls] += Lazy[n] * ((lli)(min(tam, m) - l + 1));
			Lazy[ls] += Lazy[n];
		}
		if ((m + 1) <= tam) {
			ST[rs] += Lazy[n] * ((lli)(min(tam, r) - (m + 1) + 1));
			Lazy[rs] += Lazy[n];
		}
		Lazy[n] = 0;
	}
	if ((L <= l) && (r <= R)) {
		ST[n] += ((lli)(min(tam, r) - l + 1)) * val;
		Lazy[n] += val;
		return;
	}
	
	Update(L, R, val, ls, l, m);
	Update(L, R, val, rs, m + 1, r);
	ST[n] = ST[ls] + ST[rs];
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(6);
	
	int N;
	tam = 1;
	//cin >> N;	
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int tp, ai;
		lli xi;
		//cin >> tp;
		scanf("%d", &tp);
		if (tp == 1) {
			scanf("%lld%lld", &ai, &xi);
			//cin >> ai >> xi;
			Update(1, ai, xi);
		} else if (tp == 2) {
			//cin >> xi;
			scanf("%lld", &xi);
			tam++;
			Set(tam, xi);
		} else {
			Set(tam, 0);
			tam--;
		}
		printf("%.6lf\n", (((double)ST[1]) / ((double)tam)));
		//cout << (((double)ST[1]) / ((double)tam)) << '\n';
		
	}
	
	return 0;
}