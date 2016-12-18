#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s, ss;
	cin >> s >> ss;
	int lim = s.size();
	int ok = 0;
	for (int i = 0; i < lim; ++i) {
		if (toupper(s[i]) == toupper(ss[i])) 
			continue;
		if (toupper(s[i]) < toupper(ss[i]))
			ok = -1;
		else 
			ok = 1;
		break;
	}
	cout << ok << '\n';
	return 0;
}