#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

set<lli> D, P, Gi;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N; 

	for (int i = 0; i < N; ++i) {
		lli xi;
		cin >> xi;

		if (i & 1) {
			D.clear();

			for (lli it: P) {
				lli val = __gcd(it, xi);
				D.insert(val);
				Gi.insert(val);
			}
			D.insert(xi);
			Gi.insert(xi);
		} else {
			P.clear();

			for (lli it: D) {
				lli val = __gcd(it, xi);
				P.insert(val);
				Gi.insert(val);
			}
			P.insert(xi);
			Gi.insert(xi);
		}
 	}

 	cout << Gi.size() << '\n';

	return 0;
}