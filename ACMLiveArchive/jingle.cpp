#include <bits/stdc++.h>
using namespace std; 

map<char, int> notes;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	notes['W'] = 64;
	notes['H'] = 32;
	notes['Q'] = 16;
	notes['E'] = 8;
	notes['S'] = 4;
	notes['T'] = 2;
	notes['X'] = 1;
	
	string s;
	while (cin >> s) {
		if (s[0] == '*')
			break;
		int lim = s.size();
		int cnt = 0, acum = 0;
		for (int i = 0; i < lim; ++i) {
			if (s[i] == '/') {
				if (acum == 64)
					cnt++;
				acum = 0;
			} else 
				acum += notes[s[i]];
		}
		cout << cnt << '\n';
	}
	
	return 0;
}