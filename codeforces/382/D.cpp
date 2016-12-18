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
	if (IsPrime(N)) {
		cout << 1 << '\n';
		return 0;		
	}
	int cnt = 0;
	while (N - cnt) {
		if (IsPrime(N - cnt)) {
			if ((N % (N - cnt)) == 0) {
				cout << (N / (N - cnt)) << '\n';
				break;
			} else if (IsPrime(N % (N - cnt))) {
				cout << (N / (N - cnt)) + 1 << '\n';
				break;
			}
		}
		cnt++;
	}
	return 0;
}