#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

bool IsPrime(lli xi) {
	if (xi == 1LL)
		return false;
	lli rx = floor(sqrt(xi));
	for (lli i = 2; i <= rx; ++i)
		if ((xi % i) == 0)
			return false;
	return true;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli N;
	cin >> N;
	if (IsPrime(N)) cout << "1\n";
	else if (((N % 2) == 0) || (IsPrime(N - 2LL))) cout << "2\n";
	else cout << "3\n";
	return 0;
}