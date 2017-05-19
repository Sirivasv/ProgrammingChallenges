#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100005;
const lli INF = 2000000000000000000LL;

int n, q;
lli s[MAXN], t[MAXN];

bool ok(lli ti){
	for (int i = 1; i <= n; ++i) t[i] = s[i];

	int r = n;
	lli cur = 0;
	for (int i = 1; i <= q; ++i) {
		cur = r;
		while (r >= 1) {
			if (cur + t[r] <= ti) {
				cur += t[r];
				t[r--] = 0;
			} else {
				t[r] = min(t[r], cur + t[r] - ti);
				break;
			}
		}
	}

	return r <= 0;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> n >> q;
	
	for (int i = 1; i <= n; ++i) cin >> s[i];

	while(n >= 1 && s[n] == 0) n--;
	
	lli le = 0, ri = INF, ans = 0;
	
	while (le <= ri) {
		lli mi = (le + ri) / 2LL;
		if (ok(mi)) {
			ans = mi;
			ri = mi - 1LL;
		} else le = mi + 1LL;
	}
	
	cout << ans << '\n';
	
	return 0;
}