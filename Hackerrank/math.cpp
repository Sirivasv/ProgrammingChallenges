#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long lli;

const lli MOD = 1000000007LL;
const int MAXN = 1009;

lli Fact[MAXN], C[MAXN][MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int q;
	Fact[0] = 1LL;
	for (lli i = 1; i < MAXN; ++i)
		Fact[i] = (Fact[i - 1] * i) % MOD;
	for (int i = 1; i < MAXN; ++i) {
		C[i][0] = 1LL;
		for (int j = 1; j <= i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	cin >> q;
	for (int nc = 0; nc < q; ++q) {
		int N;
		cin >> N;
		set<int> mnn;
 		for (int i = 0; i < N; ++i) {
			int xi;
			cin >> xi;
			mnn.insert(xi);
		}
		lli repe = N - mnn.size();
		lli ans = Fact[N];
		lli posans = 0;
		for (lli i = 1; i <= repe; ++i) 
			posans = (posans + (((C[repe][i]) * Fact[N - i]) % MOD)) % MOD;
		ans = (ans + MOD - posans) % MOD;
		cout << ans << '\n';
	}
    return 0;
}
