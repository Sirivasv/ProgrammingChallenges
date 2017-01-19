#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 109;

int main() {
	
	//cin.tie(0); ios_base::sync_with_stdio(0);
	//scanf("%d", &N);
	
	lli N, M, K, X, Y;
	
	cin >> N >> M >> K >> X >> Y;
	
	lli cv = (2LL * (N - 1LL)) * M;
	if (N == 1) cv = M;
	
	lli base = (K / cv) * 2LL;
	if (N == 2LL) base /= 2LL;
	lli rmod = K % cv;
	lli mats = base;
	lli mint = base;
	if (N != 2LL) mint /= 2LL;
	
	if (N == 1) mats /= 2LL;
	if (rmod > M) mats++;
	if (((rmod > (N * M))) || ((rmod < (N * M)) && (rmod > ((N - 1LL) * M)) && ((rmod % M) >= 1LL))) mats++;
	
	if ((rmod >= (N * M))) mint++;
	
	lli sergei = base;
	
	if (((X == 1LL) || (N == X)) && (N != 2LL)) sergei /= 2LL;
	
	if ((rmod >= (X * M))) sergei++;
	if (((rmod > (N * M))) && ((X * M) > (N * M))) sergei++;
	
	if ((rmod < (X * M)) && (rmod > ((X - 1LL) * M)) && ((rmod % M) >= Y)) sergei++;
	
	if (K) mats = max(mats, 1LL);
	
	cout << mats << ' ' << mint << ' ' << sergei << '\n';
	
	//printf("%lld\n", arr[0]);
	
	return 0;
}