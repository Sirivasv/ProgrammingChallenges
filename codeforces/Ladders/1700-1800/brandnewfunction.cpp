#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;
const int MAXV = 25;

int barr[MAXN];
int ST[MAXN * 3];
int lv[MAXV];
int N;

void Build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		ST[n] = barr[l];
		return;
	}
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	Build(ls, l, m);
	Build(rs, m + 1, r);
	ST[n] = ST[ls] | ST[rs];
}

int Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if ((l > R) || (r < L)) return 0;
	if ((l >= L) && (r <= R)) return ST[n];
	int ls = (n << 1), rs = ls + 1, m = (l + r) / 2;
	return Query(L, R, ls, l, m) | Query(L, R, rs, m + 1, r);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	
	set<int> numbs;
	
	for (int i = 1; i <= N; ++i) { 
		cin >> barr[i];
		numbs.insert(barr[i]);
	}
	
	Build();
	
	for (int j = 0; j < MAXV; ++j) lv[j] = 1;
	
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < MAXV; ++j) {
			numbs.insert(Query(lv[j], i));
			if (barr[i] & (1 << j)) lv[j] = i;
		}
	}
	
	cout << numbs.size() << '\n';
	
	return 0;
}