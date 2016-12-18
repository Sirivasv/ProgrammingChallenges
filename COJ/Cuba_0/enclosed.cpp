//ABCDEFGHIJKLMNOPQRSTUVWXYZ
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	map<char, int> er;
	er['A'] = 1;
	er['B'] = 2;
	er['D'] = 1;
	er['O'] = 1;
	er['P'] = 1;
	er['Q'] = 1;
	er['R'] = 1;
	string s;
	cin >> s;
	int len_ = s.size();
	int ans = 0;
	for (int i = 0; i < len_; ++i) ans += er[s[i]];
	cout << ans;
	return 0;
}