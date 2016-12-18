#include<bits/stdc++.h>
using namespace std;

map<char, int> lette;
int nc;

inline bool All(){
	for (char i = 'a'; i <= 'z'; ++i) 
		if (!lette.count(i)) return false;
	return true;
}

inline void PrintMin() {
	int  mint = 1000000;
	for (char i = 'a'; i <= 'z'; ++i) 
		mint = min(mint, lette[i]);
	cout << "Case " << nc << ": " << mint << "\n";
	return ;
}


int main() {
	int T;
	cin >> T;
	string s;
	for (nc = 1; nc <= T; ++nc) {
		cin >> s;
		int lim = s.size();
		for (int i = 0; i < lim; ++i) lette[s[i]]++;
		if (All()) PrintMin();
		else cout << "Case " << nc << ": 0\n";
		lette.clear();
	}
	return 0;
}