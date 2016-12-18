#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

bool IsPrime(lli xi) {
	if (xi == 1)
		return false;
	lli rx = floor(sqrt(xi));
	for (lli i = 2; i <= rx; ++i)
		if ((xi % i) == 0)
			return false;
	return true;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		lli xi;
		cin >> xi;
		lli cs = floor(sqrt((double)xi));
		if (((cs * cs) == xi) && (IsPrime(cs)))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}