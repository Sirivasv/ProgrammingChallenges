#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;
int N, M;
int ST[MAXN * 3];
int base[MAXN];

void Build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		if (base[l] > 0)
			ST[n] = 1;
		else if (base[l] == 0)
			ST[n] = 0;
		else
			ST[n] = -1;
		return;
	}
	int ls = n << 1, rs = ls + 1, m = (l + r) >> 1;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = ST[ls] * ST[rs];
}

void Update(int L, int val, int n = 1, int l = 1, int r = N) {
	int R = L;
	if ((l > R) || (r < L))
		return;
	if ((l >= L) && (r <= R )) {
		if (val > 0)
			ST[n] = 1;
		else if (val == 0)
			ST[n] = 0;
		else
			ST[n] = -1;
		return;
	}
	int ls = n << 1, rs = ls + 1, m = (l + r) >> 1;
	Update(L, val, ls, l, m);
	Update(L, val, rs, m + 1, r);
	ST[n] = ST[ls] * ST[rs];
}

int Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L))
		return 1;
	if ((l >= L) && (r <= R ))
		return ST[n];
	int ls = n << 1, rs = ls + 1, m = (l + r) >> 1;
	int vl = Query(L, R, ls, l, m);
	int vr = Query(L, R, rs, m + 1, r);
	return vl * vr;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N >> M) {
		for (int i = 1; i <= N; ++i)
			cin >> base[i];
		Build();
		for (int i = 0; i < M; ++i) {
			char op;
			int a, b;
			cin >> op >> a >> b;
			if (op == 'C')
				Update(a, b);
			else {
				int ans = Query(a, b);
				if (ans > 0)
					cout << '+';
				else if (ans == 0)
					cout << '0';
				else 
					cout << '-';
			}
		}
		cout << '\n';
	}
	return 0;
}