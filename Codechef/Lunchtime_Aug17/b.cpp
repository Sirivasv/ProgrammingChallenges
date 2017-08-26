#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int seen[30];
lli price[30];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	while(N--) {
		for (int i = 0; i < 26; ++i) {
			cin >> price[i];
			seen[i] = 0;
		}
		string s;
		cin >> s;
		int lim = s.size();
		for (int i = 0; i < lim; ++i) seen[s[i] - 'a'] = 1;
		lli ans = 0;
		for (int i = 0; i < 26; ++i) if (!seen[i]) ans += price[i];
		cout << ans << '\n'; 
	}
	return 0;
}