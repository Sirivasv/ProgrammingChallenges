#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli valop[10];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int id = 0, lim = s.size();
	for (id; id < lim; ++id)
		if ((s[id] >= 'a') && (s[id] <= 'f'))
			break;
	string numb = s.substr(0, id);
	lli n;
	stringstream iss(numb);
	iss >> n;
	
	map<char, lli> ctolli;
	
	ctolli['a'] = 4LL;
	ctolli['b'] = 5LL;
	ctolli['c'] = 6LL;
	ctolli['d'] = 3LL;
	ctolli['e'] = 2LL;
	ctolli['f'] = 1LL;
	
	map<lli, lli> mtolli;
	mtolli[1] = 0;
	mtolli[2] = 7LL;
	mtolli[3] = 0;
	mtolli[0] = 7LL;
	
	cout << ctolli[s[id]] + (mtolli[n % 4LL]) + ((16LL * ((n - 1LL) / 4LL))) << '\n';
	
	return 0;
}