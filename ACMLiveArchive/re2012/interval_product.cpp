#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 100009;

pii st[MAXN * 3];
int N, iarray[MAXN];
//zer first
//neg sf

void build(int n = 1, int l = 1, int r = N) {
	if (l == r) {
		if (iarray[l] < 0) 
			st[n] = pii(0, 1);
		else if (iarray[l] == 0)
			st[n] = pii(1, 0);
		else 
			st[n] = pii(0, 0);
		//cout << st[n].first << ' ' << st[n].second << '\n';
		return;
	}
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	st[n].first = st[lc].first + st[rc].first;
	st[n].second = st[lc].second + st[rc].second;
	return;
}

void update(int ID, int val, int n = 1, int l = 1, int r = N) {
	if (l > ID || r < ID) 
		return;
	if (l == r) {
		if (val < 0) 
			st[n] = pii(0, 1);
		else if (val == 0)
			st[n] = pii(1, 0);
		else 
			st[n] = pii(0, 0);
		return;
	}
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	update(ID, val, lc, l, m);
	update(ID, val, rc, m + 1, r);
	st[n].first = st[lc].first + st[rc].first;
	st[n].second = st[lc].second + st[rc].second;
	return;
}

pii Query(int L, int R, int n = 1, int l = 1, int r = N) {
	if (l > R || r < L) 
		return pii(0, 0);
	if (l >= L && r <= R) 
		return st[n];
	int lc = n << 1, rc = lc + 1, m = (l + r) >> 1;
	pii la = Query(L, R, lc, l, m);
	pii ra = Query(L, R, rc, m + 1, r);
	la.first += ra.first;
	la.second += ra.second;
	return la;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int K;
	
	while (cin >> N >> K) {
		
		for (int i = 1; i <= N; ++i)
			cin >> iarray[i];
		
		build();
		
		char op;
		int u, v;
		pii ans;
		for (int i = 0; i < K; ++i) {
			cin >> op >> u >> v;
			//cout << op << ' ' << u << ' ' << v << '\n';
			if (op == 'C') 
				update(u, v);
			else {
				ans = Query(u, v);
				if (ans.first)
					cout << '0';
				else if (ans.second & 1)
					cout << '-';
				else
					cout << '+';
			}
		}
		cout << '\n';
	}

	return 0;
}