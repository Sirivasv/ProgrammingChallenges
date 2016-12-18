#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli GetMax(lli a, lli b, lli c, lli d) {
	lli mint = min(b, min(c, d));
	return (256LL * mint);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli k1, k2, k3, k4;
	cin >> k1 >> k2 >> k3 >> k4;
	lli sum = -1;
	for (lli i = 0; i < 8; ++i) {
		lli mint = min(k1, k2);
		if (i > mint)
			break;
		lli possum = 32LL * i;
		mint = min(k1 - i, min(k3, k4));
		possum += 256LL * mint;
		mint = min(k1 - i - mint, k2 - i);
		possum += 32LL * mint;
		sum = max(possum, sum);
	}
	cout << sum << '\n';
	return 0;
}