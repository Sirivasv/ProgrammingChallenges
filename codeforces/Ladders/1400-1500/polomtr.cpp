#include <bits/stdc++.h>
using namespace std; 

typedef long long lli;

const int MAXN = 105;

lli arr[MAXN * MAXN];

lli Abs(lli x) { return((x < 0)?(-x):(x)); } 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli N, M, D;
	cin >> N >> M >> D;
	
	int ok = 1, lim = N * M;
	lli mod_d, val;
	
	cin >> val;
	mod_d = val % D;
	arr[0] = val;
	
	for (int i = 1; i < lim; ++i) {
		cin >> val;
		if ((val % D) != mod_d)
			ok = 0;
		arr[i] = val;
	}
	if (!ok) {
		cout << "-1\n";
		return 0;
	}
	sort(arr, arr + lim);
	lli median = arr[lim / 2];
	lli ans = 0;
	for (int i = 0; i < lim; ++i)
		ans += Abs(arr[i] - median) / D;
	cout << ans << '\n';
	return 0;
}