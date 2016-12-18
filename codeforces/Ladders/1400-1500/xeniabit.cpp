#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = (1 << 18);

lli ST[MAXN * 3], barr[MAXN];

int N, p;

void Build(int n = 1, int l = 1, int r = N, int lev = 1) {
	if (l == r) {
		ST[n] = barr[l];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Build(ls, l, m, lev + 1);
	Build(rs, m + 1, r, lev + 1);
	if ((lev & 1) == (p & 1))
		ST[n] = ST[ls] | ST[rs];
	else
		ST[n] = ST[ls] ^ ST[rs];
}

void Update(int id, lli v, int n = 1, int l = 1, int r = N, int lev = 1) {
	if ((l > id) || (r < id))
		return;
	if (l == r) {
		ST[n] = v;
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Update(id, v, ls, l, m, lev + 1);
	Update(id, v, rs, m + 1, r, lev + 1);
	if ((lev & 1) == (p & 1))
		ST[n] = ST[ls] | ST[rs];
	else
		ST[n] = ST[ls] ^ ST[rs];
} 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int M;
	cin >> p >> M;
	N = (1 << p);
	for (int i = 1; i <= N; ++i)
		cin >> barr[i];
	Build();
	for (int i = 0; i < M; ++i) {
		lli nv;
		int pos;
		cin >> pos >> nv;
		Update(pos, nv);
		cout << ST[1] << '\n';
	}
	return 0;
}