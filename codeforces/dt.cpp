#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main () {
	lli N;
	cin >> N;
	lli a, b, c;
	cin >> a >> b >>c;
	
	lli mint = (1LL << 62);
	//cout << mint << '\n';
	
	for (lli i = 0; i <= 100LL; ++i)
		for (lli j = 0; j <= 100LL; ++j)
			for (lli k = 0; k <= 100LL; ++k)
				if ((((i) + (2LL * j) + (3LL * k) + N) % 4LL) == 0)
					mint = min(mint, (a * i) + (b * j) + (c * k));
	cout << mint << '\n';
	return 0;
}