#include <bits/stdc++.h>
using namespace std;

const int MAXC = 30;

int arrs[MAXC], arrpi[MAXC];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s, ss, pi;
	cin >> s >> ss >> pi;
	int lim = s.size();
	for (int i = 0; i < lim; ++i)
		arrs[s[i] - 'A']++;
	lim = ss.size();
	for (int i = 0; i < lim; ++i)
		arrs[ss[i] - 'A']++;
	lim = pi.size();
	for (int i = 0; i < lim; ++i)
		arrpi[pi[i] - 'A']++;
	int ok = 1;
	for (int i = 0; i < MAXC; ++i)
		if (arrs[i] != arrpi[i])
			ok = 0;
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}