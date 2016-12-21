#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

lli arr[MAXN];

int N;

bool CanPlay(lli xi) {
	lli sum = 0;
	for (int i = 0; i < N; ++i) 
		sum += (xi - arr[i]);
	return (sum >= xi);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	lli mats = -1LL;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		mats = max(mats, arr[i]);
	}
	
	lli ini = mats, fin = 2000000000LL, ans = mats;
	
	while (ini <= fin) {
		lli m = (ini + fin) / 2LL;
		if (CanPlay(m)) {
			ans = m;
			fin = m - 1LL;
		} else ini = m + 1LL;
	}
	
	cout << ans << '\n';
	
	return 0;
}