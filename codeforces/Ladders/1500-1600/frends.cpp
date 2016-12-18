#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli ci, cj, xi, yi;

bool Check (lli n) {
	lli val = n - (n / xi) - (n / yi) + (n / (xi * yi));
	lli vali = (n / yi) - (n / (xi * yi));
	lli valj = (n / xi) - (n / (xi * yi));
	return (val >= (max(0LL, ci - vali) + max(0LL, cj - valj)));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> ci >> cj >> xi >> yi;
	lli ini = 1LL, fin = 1000000000000000000LL, ans = -1;
	while (ini <= fin) {
		lli m = (ini + fin) / 2LL;
		if (Check(m)) {
			ans = m;
			fin = m - 1LL;
		} else ini = m + 1LL;
	}
	cout << ans << '\n';
	return 0;
}