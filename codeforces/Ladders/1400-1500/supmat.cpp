#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s, ss;
	cin >> s >> ss;
	int lim = s.size();
	for (int i = 0; i < lim; ++i)
		if (s[i] != ss[i])
			s[i] = '1';
		else 
			s[i] = '0';
	cout << s << '\n';
	return 0;
}