#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int ST[MAXN * 3], arr[MAXN], N, Q;

void Build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		ST[n] = arr[l];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = ST[ls] * ST[rs];
}

void Update(int id, int v, int n = 1, int l = 1, int r = N) {
	if ((id > r) || (id < l))
		return;
	if (l == r) {
		ST[n] = v;
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	Update(id, v, ls, l, m);
	Update(id, v, rs, m + 1, r);
	ST[n] = ST[ls] * ST[rs];
}

int Query(int L, int R, int n = 1, int l = 1, int r = N) {
	
	if ((L > r) || (R < l))
		return 1;
	if ((L <= l) && (r <= R))
		return ST[n];
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	int lq = Query(L, R, ls, l, m);
	int rq = Query(L, R, rs, m + 1, r);
	return (lq * rq);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N >> Q) {
		for (int i = 1; i <= N; ++i) {
			cin >> arr[i];
			if (arr[i] < 0)
				arr[i] = -1;
			else if (arr[i] > 0)
				arr[i] = 1;
		}
		Build();
		for (int i = 0; i < Q; ++i) {
			char op;
			cin >> op;
			if (op == 'C') {
				int id, v;
				cin >> id >> v;
				if (v < 0)
					v = -1;
				else if (v > 0)
					v = 1;
				Update(id, v);
			} else {
				int I, J;
				cin >> I >> J;
				int resq = Query(I, J);
				if (resq == 0)
					cout << 0;
				else if (resq < 0)
					cout << '-';
				else
					cout << '+';
			}
		}
		cout << '\n';
	}
	return 0;
}