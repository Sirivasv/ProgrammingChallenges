#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;
const int INF = 1000000009;

int ST[MAXN * 4], N, arr[MAXN];

void build(int l = 1, int r = N, int n = 1) {
	if (l == r) {
		ST[n] = arr[l];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	build(l, m, ls);
	build(m + 1, r, rs);
	ST[n] = min(ST[ls], ST[rs]);
}

int Query(int L, int R, int l = 1, int r = N, int n = 1) {
	if ((l >= L) && (r <=R)) return ST[n]; 
	if ((l > R) || (r < L)) return INF;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	return min(Query(L, R, l, m, ls), Query(L, R, m + 1, r, rs));
}

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	while (cin >> N) {
		for (int i = 1; i <= N; ++i) cin >> arr[i];
		build();
		int M;
		cin >> M;

		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			if (a > b) swap(a, b);
			cout << Query(a, b) << '\n';
		}
	}
	return 0;
}