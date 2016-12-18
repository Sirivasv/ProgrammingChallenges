#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	//put only pairs or single letters
	string ns = s;
	ns[0] = s[0];
	char c = s[0];
	int mn = 1;
	int nlenght = 1;
	int lim = s.size();
	for (int i = 1; i < lim; ++i) {
		if (s[i] == c) {
			if (mn == 1)
				ns[nlenght++] = c;
			mn++;
		} else {
			c = s[i];
			mn = 1;
			ns[nlenght++] = c;
		}
	}
	for (int i = 0; i < nlenght; ++i) {
		if (!((i + 3) < nlenght))
			break;
		if ((ns[i] == ns[i + 1]) && (ns[i + 2] == ns[i + 3]))
			ns[i + 2] = 0;
	}
	
	for (int i = 0; i < nlenght; ++i)
		if(ns[i])
			cout << ns[i];
	cout << '\n';
	
	return 0;
}