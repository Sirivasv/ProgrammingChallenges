#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli need[5], have[5], cost[5], mh;

bool Can(lli m) {
	lli mn = 0;
	for (int i = 0; i < 3; ++i) 
		mn += (max(((need[i] * m) - have[i]), 0LL)) * cost[i];
	return (mh >= mn);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	
	int lim = s.size();
	for (int i = 0; i < lim; ++i)
		if (s[i] == 'B')
			need[0]++;
		else if (s[i] == 'S')
			need[1]++;
		else
			need[2]++;
	
	for (int i = 0; i < 3; ++i)
		cin >> have[i];
	for (int i = 0; i < 3; ++i)
		cin >> cost[i];
	cin >> mh;
	
	lli ini = 0, fin = 10000000000000LL, ans = 0;
	while (ini <= fin) {
		lli m = (ini + fin) / 2LL;
		if (Can(m)) {
			ans = m;
			ini = m + 1;
		} else 
			fin = m - 1;
	}
	cout << ans << '\n';
	return 0;
}