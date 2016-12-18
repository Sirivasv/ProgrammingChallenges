#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100009;

int st[MAXN * 3], arr[MAXN], N, M;
string s;

void build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		st[n] = arr[l - 1];
		if (((N - l) % 2))
			st[n] *= -1;
		return;
	}
	int lc = (n << 1), rc = lc + 1, m = ((l + r) >> 1); 
	build(lc, l, m);
	build(rc, m + 1, r);
	st[n] = st[lc] + st[rc];
	return;
}

int Query(int L = 1, int R = N, int n = 1, int l = 1, int r = N) {
	if (l > R || r < L) return 0;
	if (l >= L && r <= R) return st[n];
	int lc = (n << 1), rc = lc + 1, m = ((l + r) >> 1);
	return Query(L, R, lc, l, m) + Query(L, R, rc, m + 1, r);	
}

void UpdateCh(int id, int val, int n = 1, int l = 1, int r = N) {
	if (l > id || r < id) return;
	if (l == r) {
		st[n] = val;
		if (((N - l) % 2))
			st[n] *= -1;
		return;
	}
	int lc = (n << 1), rc = lc + 1, m = ((l + r) >> 1); 
	UpdateCh(id, val, lc, l, m);
	UpdateCh(id, val, rc, m + 1, r);
	st[n] = st[lc] + st[rc];
	return;
}

void UpdateX(int id, int n = 1, int l = 1, int r = N) {
	if (l > id || r < id) return;
	if (l == r) {
		if (st[n] == 1 || st[n] == -1) 
			st[n] = 0;
		else
			st[n] = 1;
		if (((N - l) % 2))
			st[n] *= -1;
		return;
	}
	int lc = (n << 1), rc = lc + 1, m = ((l + r) >> 1); 
	UpdateX(id, lc, l, m);
	UpdateX(id, rc, m + 1, r);
	st[n] = st[lc] + st[rc];
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N  >> M;
	cin >> s;
	for (int i = 0; i < N; ++i)
		arr[i] = s[i] - '0';
	build();
	char op;
	int ind, val;
	while (M--) {
		cin >> op;
		if (op == 'C') {
			cin >> ind;
			ind = N - ind;
			UpdateX(ind);
		} else if (op == 'P') {
			val = Query();
			if (val % 3)
				cout << "No\n";
			else 
				cout << "Yes\n";
		} else {
			cin >> ind >> val;
			ind = N - ind;
			UpdateCh(ind, val);
		}
	}
	return 0;
}