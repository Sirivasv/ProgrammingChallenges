#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int BIT[MAXN], sz;

void Update(int idx) {
	while (idx < MAXN) {
		BIT[idx]++;
		idx += (idx & (-idx));
	}
}

int Query(int idx) {
	int res = 0;
	while (idx) {
		res += BIT[idx];
		idx -= (idx & (-idx));
	}
	return res;
}

int getMedian() {
	int lim = (sz + 1) / 2, ini = 2, fin = MAXN - 1, m, ans;
	while (ini <= fin) {
		m = (ini + fin) >> 1;
		if (Query(m) >= lim) {
			ans = m;
			fin = m - 1;
		} else 
			ini = m + 1;
	}
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, x;
	cin >> N >> x;
	x++;
	sz = N;
	
	for (int i = 0; i < N; ++i) {
		int ax;
		cin >> ax;
		ax++;
		Update(ax);
	}
	
	int ans = 0;
	
	if ((Query(x) - Query(x - 1)) == 0) {
		ans++;
		sz++;
		Update(x);
	}
	
	int med = getMedian();
	while(med != x) {
		//cout << med << ' ' << x << '\n';
		if (med > x)
			Update(x - 1);
		else
			Update(x + 1);
		sz++;
		ans++;
		med = getMedian();
	}
	cout << ans << '\n';
	return 0;
}