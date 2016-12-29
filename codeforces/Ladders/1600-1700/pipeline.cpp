#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli Check(lli m, lli K) {
	return ((K * (K - 1LL)) / 2LL) - ((m * (m - 1LL)) / 2LL);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	lli N, K;
	cin >> N >> K;
	
	if ((N - 1) > ((K * (K - 1LL)) / 2LL)) {
		cout << "-1\n";
		return 0;
	}
	
	if (N == 1) {
		cout << "0\n";
		return 0;
	}
	
	lli ini = 1LL, fin = K, ans = 1LL;
	
	while (ini <= fin) {
		lli m = (ini + fin) / 2LL;
		if (Check(m, K) < N) {
			ans = m;
			fin = m - 1LL;
		} else ini = m + 1LL;
	}
	
	if (Check(ans, K) == (N - 1LL)) cout << (K - ans) << '\n';
	else cout << (K - ans + 1LL) << '\n';
	
	return 0;
}