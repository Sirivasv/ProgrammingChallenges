#include <bits/stdc++.h>
using namespace std;

bool HasEnding(string s) {
	int lim = s.size() - 1;
	for (int i = 0; i < lim; ++i)
		if (s[i] == '*' && s[i + 1] == '/') return true;
	return false;
}

void Check(string s) {
	int lim = s.size() - 1;
	int foundc = 0;
	string ax;
	for (int i = 0; i < lim; ++i) {
		if (s[i] == '/' && s[i + 1] == '/') return;
		if (s[i] == '/' && s[i + 1] == '*') {
			if (HasEnding(s)) {
				for (; i < lim; ++i)
					if (s[i] == '*' && s[i + 1] == '/')
						break;
				i++;
				if (i >= lim) return;
				continue;
			} else {
				while (getline(cin, ax)) {
					if (HasEnding(ax)) { 
						foundc = 1;
						break;
					}
				}
				if (foundc) {
					int limm = ax.size() - 1, j = 0;
					for (; j < limm; ++j){
						if (ax[j] == '*' && ax[j + 1] == '/')
							break;
					}
					Check(ax.substr(j + 2));
				}
				return;
			}
		}
		cout << s[i];
	}
	if (lim >= 0) cout << s[lim];
}

int main() {
	int N;
	cin >> N;
	cin.ignore();
	string s;
	while (getline(cin, s)) {
		Check(s);
		cout << '\n';
	}
	return 0;
}