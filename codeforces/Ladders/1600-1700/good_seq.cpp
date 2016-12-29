#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const lli MAXN = 100009;

int dp[MAXN];

vector<lli> Primes;
bitset<MAXN> isp;

void Criba() {
	lli lim = sqrt(MAXN);
	isp[0] = isp[1] = 1;
	for (lli j = 4; j < MAXN; j += 2LL)
		isp[j] = 1;
	
	for (lli i = 3LL; i <= lim; i += 2LL) {
		if (!isp[i]) {
			for (lli j = i * i; j < MAXN; j += i)
				isp[j] = 1;
		}
	}
	for (lli i = 2; i < MAXN; ++i)
		if (!isp[i])
			Primes.push_back(i);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	Criba();
	int Plim = Primes.size(), N;
	
	cin >> N;
	
	int ans = 0;
	
	for (int i = 0; i < N; ++i) {
		lli xi;
		cin >> xi;
		int posans = 0;
		
		lli lim = xi;
		if (isp[xi]) {
			for (int j = 0; j < Plim; ++j) {
				if (Primes[j] > lim) break;
				if ((lim % Primes[j]) == 0) {
					posans = max(dp[Primes[j]], posans);
					while ((lim % Primes[j]) == 0) lim /= Primes[j];
				}
			}
			if (!isp[lim]) posans = max(dp[lim], posans);
		} else posans = max(dp[xi], posans);
			
		posans++;
		ans = max(ans, posans); 
		
		lim = xi;
		if (isp[xi]) {
			for (int j = 0; j < Plim; ++j) {
				if (Primes[j] > lim) break;
				if ((lim % Primes[j]) == 0) {
					dp[Primes[j]] = posans;
					while ((lim % Primes[j]) == 0) lim /= Primes[j];
				}
			}
			if (!isp[lim]) dp[lim] = posans;
		} else dp[xi] = posans;
	}
	
	cout << ans << '\n';
	
	return 0;
}