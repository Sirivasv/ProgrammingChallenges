#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;
const int LOGN = 20;

int ST[MAXN * 4][LOGN], arr[MAXN], Lazy[MAXN * 4][LOGN], N;
long long ansq[LOGN];

void Build(int n = 1, int L = 1, int R = N) {
	if (L == R) {
		for (int i = 0; i < LOGN; ++i)
			if (arr[L] & (1 << i))
				ST[n][i]++;
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (L + R) >> 1;
	
	Build(ls, L, m);
	Build(rs, m + 1, R);
	for (int i = 0; i < LOGN; ++i)
		ST[n][i] = ST[ls][i] + ST[rs][i];
}

void Update(int l, int r, int x, int n = 1, int L = 1, int R = N) {
	if ((L > r) || (R < l))
		return;
	int ls = (n << 1), rs = ls + 1, m = (L + R) >> 1;
	if (L != R) {
		for (int i = 0; i < LOGN; ++i)
			if (Lazy[n][i]) {
				int ltam = (m - L + 1);
				int rtam = (R - (m + 1) + 1);
				ST[ls][i] = ltam - ST[ls][i];
				ST[rs][i] = rtam - ST[rs][i];
				Lazy[ls][i] ^= 1;
				Lazy[rs][i] ^= 1;
				Lazy[n][i] = 0;
			}
	}
	if ((L >= l) && (R <= r)) {
		for (int i = 0; i < LOGN; ++i) {
			if (x & (1 << i)) {
				int tam = R - L + 1;
				ST[n][i] = tam - ST[n][i];
				Lazy[n][i] ^= 1;
			}
		}
		return;
	}
	Update(l, r, x, ls, L, m);
	Update(l, r, x, rs, m + 1, R);
	for (int i = 0; i < LOGN; ++i)
		ST[n][i] = ST[ls][i] + ST[rs][i];
}

void Query(int l, int r, int n = 1, int L = 1, int R = N) {
	if ((L > r) || (R < l))
		return;
	int ls = (n << 1), rs = ls + 1, m = (L + R) >> 1;
	if (L != R) {
		for (int i = 0; i < LOGN; ++i)
			if (Lazy[n][i]) {
				int ltam = (m - L + 1);
				int rtam = (R - (m + 1) + 1);
				ST[ls][i] = ltam - ST[ls][i];
				ST[rs][i] = rtam - ST[rs][i];
				Lazy[ls][i] ^= 1;
				Lazy[rs][i] ^= 1;
				Lazy[n][i] = 0;
			}
	}
	if ((L >= l) && (R <= r)) {
		for (int i = 0; i < LOGN; ++i)
			ansq[i] += ST[n][i];
		return;
	}
	Query(l, r, ls, L, m);
	Query(l, r, rs, m + 1, R);
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
		int op, I, J, x;
		cin >> op;
		if (op == 1) {
			cin >> I >> J;
			for (int j = 0; j < LOGN; ++j)
				ansq[j] = 0;
			Query(I, J);
			long long sum = 0;
			for (int j = 0; j < LOGN; ++j)
				sum += (long long)(ansq[j] * (1LL << j));
			cout << sum << '\n';
		} else {
			cin >> I >> J >> x;
			Update(I, J, x);
		}
	}
	return 0;
}