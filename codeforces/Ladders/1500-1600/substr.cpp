#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 30;

map<pii, lli> mp;

lli cst[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < 26; ++i)
		cin >> cst[i];
	string s;
	cin >> s;
	int lim = s.size();
	
	lli acum = 0;
	lli ans = 0;
	for (int i = 0; i < lim; ++i) {
		acum += cst[s[i] - 'a'];
		if ((i) && (i < (lim - 1)) && (mp.count(pii(acum, s[i + 1] - 'a'))))
			ans += mp[pii(acum, s[i + 1] - 'a')];
		mp[pii(acum, s[i] - 'a')]++;
	}
	lim--;
	for (int i = 0; i < lim; ++i)
		if (s[i] == s[i + 1])
			ans++;
	cout << ans << '\n';
	return 0;
}