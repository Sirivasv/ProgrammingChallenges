#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int cnt = 0, lim = s.size();
	char lc = -1;
	int ok = 0;
	for (int i = 0; i < lim; ++i) {
		if (s[i] == lc) {
			cnt++;
		} else {
			if (cnt >= 7)
				ok = 1;
			cnt = 1;
		}
		lc = s[i];
	}
	if (cnt >= 7)
		ok = 1;
	cout << ((ok)?("YES\n"):("NO\n"));	
	return 0;
}