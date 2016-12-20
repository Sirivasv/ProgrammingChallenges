#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	
	lli N, K;
	
	cin >> N >> K;
	
	if (K > ((N + 1LL) / 2LL)) {
		K -= ((N + 1LL) / 2LL);
		cout << (K * 2LL) << '\n';
	} else cout << ((K * 2LL) - 1LL) << '\n';
	
	return 0;
}