#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli N, a, b;
	cin >> N >> a >> b;
	N *= 6LL;
	if ((a * b) >= N) {
		cout << (a * b) << '\n';
		cout << a << ' ' << b << '\n';
		return 0;
	}
	lli lim = ceil(sqrt(N));
	lli matsA = (1LL << 62), L, R;
	lli mint = min(a, b), mats = max(a, b);
	for (lli i = mint; i <= lim; ++i) {
		lli j = ceil((double)N / (double)i);
		if (((i * j) < matsA) && (j >= mats)) {
			matsA = i * j;
			L = i; R = j;
		}
	}
	if (a > b)
		swap(L, R);
	cout << matsA << '\n';
	cout << L << ' ' << R << '\n';
	return 0;
}