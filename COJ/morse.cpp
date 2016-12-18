#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pic;
map<char, int> mcars;

int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	mcars['.'] = 1;
	mcars['-'] = 5;
	mcars[':'] = 2;
	mcars['='] = 10;
	int N;
	cin >> N;
	string expr;
	getline(cin, expr);
	int lim = expr.size();
	map <int, pic> mp;
	int elem = 0, sum = 0;
	for (int i = 0; i < N; ++i) {
		if (mcars.count(expr[i])) {
			sum += mcars[expr[i]];
		} else {
			mp[elem++] = pic(sum, '#');
			mp[elem++] = pic(-1, expr[i]);
			sum = 0;
		}
	}
	mp[elem++] = pic(sum, '#');
	while (elem != 1) {
		map<int, pic> nmp;
		int fndm = 0, nelem = 0;
		for (int i = 0; i < elem; ++i) {
			if ((mp[i].second == '*') && (!fndm)) {
				fndm++;
				nmp[nelem++] = pic(mp[i - 1].first * mp[i + 1].first, '#'); 
				i++;
				cout << "dd\n";
			} else nmp[nelem++] = mp[i];
		}
		if (!fndm) {
			nelem = 0;
			fndm = 0;
			for (int i = 0; i < elem; ++i) {
				if ((mp[i].second == '+') && (!fndm)) {
					fndm++;
					nmp[nelem++] = pic(mp[i - 1].first + mp[i + 1].first, '#'); 
					i++;
				} else nmp[nelem++] = mp[i];
			}
		}
		cout << nelem << '\n';
		int ax;
		//cin >> ax;
		elem = nelem;
		mp = nmp;
	}
	cout << mp[0].first << '\n';
	return 0;
}