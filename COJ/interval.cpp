#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;
const int INF = 1000000;

int STneg[MAXN * 4], STz[MAXN * 4], N, arr[MAXN];

void UpdateN(int pos, int val, int l = 1, int r = N, int n = 1) {
	if ((l == r) && (l == pos)) {
		STneg[n] = val;
		return;
	}
	if ((l > pos) || (r < pos)) return;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	UpdateN(pos, val, l, m, ls);
	UpdateN(pos, val, m + 1, r, rs);
	STneg[n] = (STneg[ls] + STneg[rs]);
}

int QueryN(int L, int R, int l = 1, int r = N, int n = 1) {
	if ((l >= L) && (r <=R)) return STneg[n]; 
	if ((l > R) || (r < L)) return 0;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	return QueryN(L, R, l, m, ls) + QueryN(L, R, m + 1, r, rs);
}

void UpdateZ(int pos, int val, int l = 1, int r = N, int n = 1) {
	if ((l == r) && (l == pos)) {
		STz[n] = val;
		return;
	}
	if ((l > pos) || (r < pos)) return;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	UpdateZ(pos, val, l, m, ls);
	UpdateZ(pos, val, m + 1, r, rs);
	STz[n] = (STz[ls] + STz[rs]);
}

int QueryZ(int L, int R, int l = 1, int r = N, int n = 1) {
	if ((l >= L) && (r <=R)) return STz[n]; 
	if ((l > R) || (r < L)) return 0;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	return QueryZ(L, R, l, m, ls) + QueryZ(L, R, m + 1, r, rs);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int M;
	while (cin >> N >> M) {

		for (int i = 1; i <= N; ++i) {
			UpdateN(i, 0);
			UpdateZ(i, 0);
		}

		for (int i = 1; i <= N; ++i) {
			int val;
			cin >> val;
			if (val < 0) UpdateN(i, 1);
			if (val == 0) UpdateZ(i, 1);
		}

		for (int i = 0; i < M; ++i) {
			char c;
			int a, b; 
			cin >> c >> a >> b;
			if (c == 'C') {
				UpdateZ(a, 0);
				UpdateN(a, 0);
				if (b < 0) UpdateN(a, 1);
				if (b == 0) UpdateZ(a, 1);
			} else {
				int nz = QueryZ(a, b);
				if (nz) {
					cout << '0';
				} else {
					int nn = QueryN(a, b);
					if (nn & 1) cout << '-';
					else cout << '+';
				}
			}
		}
		cout << '\n';

	}

	return 0;
}