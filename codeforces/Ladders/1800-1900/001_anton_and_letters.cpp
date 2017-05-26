#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	string s;
	getline(cin, s);
	set<char> mys;
	int l = s.size();
	for (int i = 0; i < l; ++i)
		if ((s[i] >= 'a') && (s[i] <= 'z'))
			mys.insert(s[i]); 
	cout << mys.size() << '\n';
	return 0;
}