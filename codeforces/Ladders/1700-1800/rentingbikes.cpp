#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 100009;

lli A, pm[MAXN], rp[MAXN];
int N, M;

pii Check(int xi) {
	pii res = pii(0, 0);
	lli pma = 0, sma = 0;
	for (int i = 0; i < xi; ++i) {
		if (((A + sma) + pm[i]) < rp[xi - 1 - i]) return res;
		pma += min(pm[i], rp[xi - 1 - i]);
		sma += min(0LL, pm[i] - rp[xi - 1 - i]);
	}
	res.first = 1;
	res.second = max(0LL, pma - (A + sma));
	return res;
}

pii BusBin() {
	int ini = 1, fin = min(N, M);
	pii ans = pii(0, 0);
	
	while (ini <= fin) {
		int m = (ini + fin) / 2;
		pii ac = Check(m);
		if (ac.first) {
			ans.first = m;
			ans.second = ac.second;
			ini = m + 1;
		} else fin = m - 1;
	}
	
	return ans;
}

int main() {
	
	scanf("%d%d%lld", &N, &M, &A);
	
	for (int i = 0; i < N; ++i) scanf("%lld", &pm[i]);
	for (int i = 0; i < M; ++i) scanf("%lld", &rp[i]);
	
	sort(pm, pm + N, greater<lli>());
	sort(rp, rp + M);
	
	pii BB = BusBin();
	
	printf("%lld %lld\n", BB.first, BB.second);
	
	return 0;
}