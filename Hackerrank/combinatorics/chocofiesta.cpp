#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MOD = 1000000007;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	lli mp = 0, mip = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) { 
		int xi; cin >> xi; 
		if (xi & 1) mip++; 
		else mp++; 
	}
	lli pot = N;
	if (mip) pot--;
	lli b = 2LL, res = 1LL;
	while (pot) {
		if (pot & 1) res = (b *  res) % MOD;
		b = (b * b) % MOD;
		pot >>= 1;
	}
	cout << res - 1LL << '\n';
    return 0;
}
