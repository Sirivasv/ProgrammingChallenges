#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	lli a, b, n, m;

	cin >> a >> b >> n >> m;
	
	a %= n;	
	b %= m;

	lli lim = (n * m) / __gcd(n, m);		

	for (int i = 0; i <= lim; ++i)
		if (((i%n) == a) && ((i%m) == b)) {
			cout << i << '\n';
			break;
		}
			
	
	return 0;
}
