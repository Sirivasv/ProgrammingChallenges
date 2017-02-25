#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli acum[4009];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	string s;
	
	lli a, lim;
	
	cin >> a >> s;
	
	for (int i = 1; i <= s.size(); ++i)
		acum[i] = acum[i - 1] + (s[i - 1] - '0');
	
	map<lli, lli> mp;
 	
	for (int i = 1; i <= s.size(); ++i) 
		for (int j = 0; j < i; ++j)
			mp[acum[i] - acum[j]]++;
	
	lli ans = 0;
	lim = acum[s.size()];
	
	if (a) {
		for(lli i = 1; (i <= lim) && ((i * i) <= a); ++i)
			if (((a % i) == 0) && ((a / i) <= lim))
				ans += mp[i] * mp[a / i] * (((i * i) == a)?1LL:2LL);
	} else ans = mp[0] * (((s.size() + 1LL) * s.size()) - mp[0]);
	
	cout << ans << '\n';
	
	
	return 0;
}