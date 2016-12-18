#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;

bitset<MAXN> BS;

int main() {
	string s;
	cin >> s;
	int lim = s.size() - 2;
	for (int i = 0; i < lim; ++i) {
		if ((s[i] == 'W') && (s[i + 1]  == 'U') && (s[i + 2] == 'B'))
			BS[i] = BS[i + 1] = BS[i + 2] = 1;
	}
	lim = s.size();
	int id = 0;
	while (id < lim) {
		while ((BS[id]) && (id < lim)) {
			id++;
		}
		while ((!BS[id]) && (id < lim)) {
			cout << s[id];
			id++;
		}
		cout << ' ';
	}
	cout << '\n';
	return 0;
}