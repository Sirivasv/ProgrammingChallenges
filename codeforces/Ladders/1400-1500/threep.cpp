#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

lli Abs(lli x) { return((x < 0)?(-x):(x)); }

lli arr[MAXN];

int BusBin(int id, lli dis, int N) {
	int ini = id + 1, fin = N - 1, m, ans = id;
	while (ini <= fin) {
		m = (ini + fin) / 2;
		if (Abs(arr[id] - arr[m]) <= dis) {
			ans = m;
			ini = m + 1;
		} else
			fin = m - 1;
	}
	return ans;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	lli d;
	cin >> N >> d;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	lli ans = 0;
	for (int i = 0; i < N; ++i) {
		int r = BusBin(i, d, N);
		//cout << i << ' ' << r << '\n';
		lli pans =  max(((r - i + 1) - 2), 0);
		ans += (pans * (pans + 1LL)) / 2LL;
	}
	cout << ans << '\n';
	return 0;
}