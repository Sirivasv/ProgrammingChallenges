#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 1000009;

lli arr[MAXN], val[MAXN], M;

int N, W;

lli Need(lli xi) {
	lli n = 0;
	for (int i = 0; i < N; ++i) val[i] = 0;
	lli acum = 0;
	for (int i = 0; i < N; ++i) {
		acum += val[i];
		if ((arr[i] + acum) >= xi)
			continue;
		lli tmp = xi - (arr[i] + acum);
		acum += tmp;
		n += tmp;
		val[i + W] -= tmp;
	}
	return n;
} 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N >> M >> W;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	lli ini = 0LL, fin = 1010000000LL, ans = 0LL;
	while (ini <= fin) {
		lli m = (ini + fin) / 2LL;
		if (Need(m) <= M) {
			ans = m;
			ini = m + 1LL;
		} else fin = m - 1LL;
	}
	cout << ans << '\n';
	return 0;
}