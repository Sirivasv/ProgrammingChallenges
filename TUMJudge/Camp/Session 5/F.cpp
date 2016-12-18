#include <bits/stdc++.h>
using namespace std;

bool IsPrime(long long x) {
	if (x == 1LL)
		return false;
	if (x == 2LL)
		return false;
	if (!(x & 1))
		return false;
	for (long long i = 3LL; (i * i) <= x; i += 2LL)
		if ((x % i) == 0)
			return false;
	return true;
}

bool IsHP(int x) {
	for (int i = 0; i < 10009; ++i) {
		int nx = 0;
		while (x) {
			int md = (x % 10);
			x /= 10;
			nx += (md * md);
		}
		if (nx == 1)
			return true;
		x = nx;
	}
	return false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for(int nc = 1; nc <= T; ++nc) {
		long long N, A;
		cin >> A >> N;
		if (!IsPrime(N)) {
			cout << A << ' ' << N << " NO\n";
			continue;
		} else {
			if (IsHP((int)N))
				cout << A << ' ' << N << " YES\n";
			else
				cout << A << ' ' << N << " NO\n";
		}
	}
	
	return 0;
}