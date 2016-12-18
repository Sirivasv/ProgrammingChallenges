#include <bits/stdc++.h>
using namespace std;

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s, x;
	while (cin >> s) {
		if (s.size() == 1 && s[0] == '0')
			break;
		cin >> x;
		map<char, int> frqS, frqX;
		int lim = s.size();
		for (int i = 0; i < lim; ++i)
			frqS[s[i]]++;
		lim = x.size();
		for (int i = 0; i < lim; ++i)
			frqX[x[i]]++;
		int valid = 1;
		for (map<char, int>::iterator it = frqX.begin(); it != frqX.end(); it++) {
			char c = (*it).first;
			int val = (*it).second;
			if (val != frqS[c]) {
				valid = 0;
				break;
			}
		} 
		if (valid)
			cout << "POSIBLE\n";
		else 
			cout << "IMPOSIBLE\n";
	}
	return 0;
}