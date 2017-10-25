#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

int ST[MAXN * 4], N, arr[MAXN];

void build(int l = 1, int r = N, int n = 1) {
	if (l == r) {
		ST[n] = arr[l];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	build(l, m, ls);
	build(m + 1, r, rs);
	ST[n] = max(ST[ls], ST[rs]);
}

int Query(int L, int R, int l = 1, int r = N, int n = 1) {
	if ((l >= L) && (r <=R)) return ST[n]; 
	if ((l > R) || (r < L)) return -1;
	int ls = (n << 1), rs = ls + 1, m = (l + r) >> 1;
	return max(Query(L, R, l, m, ls), Query(L, R, m + 1, r, rs));
}

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	int M;
	cin >> N >> M;
	map<lli, int> mp;
	lli sum = 0;

	mp[0] = 1;

	for (int i = 1; i <= N; ++i) {
		lli val;
		cin >> val;
		sum += val;
		if (mp.count(sum)) arr[i] = mp[sum] + 1;
		else arr[i] = -1;
		if (val == 0) arr[i] = i;
		mp[sum] = i;
		//cout << arr[i] << "*\n";
	}

	build();

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		int id = Query(a, b);
		//cout << id << '\n';
		if (id < a) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}