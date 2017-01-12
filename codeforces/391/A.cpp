#include <bits/stdc++.h>
using namespace std;

//Si ordenas recuerda los ID XD

//Binaria, Greedy, Sortings, Estructuras, Strings, Grafos, Mates, DP, combinaciones entre las anteriores

typedef long long lli;

const int MAXN = 100009;

lli arr[MAXN];
int N;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	string s;

	cin >> s;
	
	map<char, int> mp;
	
	mp['B'] = 0;
	mp['u'] = 0;
	mp['l'] = 0;
	mp['b'] = 0;
	mp['a'] = 0;
	mp['s'] = 0;
	mp['r'] = 0;
	
	int lim = s.size();
	for (int i = 0; i < lim; ++i) 
		mp[s[i]]++;
	
	int mint = MAXN;
	mint = min(mint, mp['B']);
	mint = min(mint, mp['u'] / 2);
	mint = min(mint, mp['l']);
	mint = min(mint, mp['b']);
	mint = min(mint, mp['a'] / 2);
	mint = min(mint, mp['s']);
	mint = min(mint, mp['r']);
	
	cout << mint << '\n';
	
	return 0;
}