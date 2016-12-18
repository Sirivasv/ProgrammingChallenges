#include <bits/stdc++.h>
using namespace std;

bool IsVowel(char c) {
	return ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U') || (c == 'Y'));
}

int main() {
	string s;
	cin >> s;
	vector<char> ns;
	int lim = s.size();
	for (int i = 0; i < lim; ++i) {
		if (IsVowel((char)toupper(s[i])))
			continue;
		ns.push_back((char)tolower(s[i]));
	}
	lim = ns.size();
	for (int i = 0; i < lim; i++)
		cout << '.' << ns[i];
	cout << '\n';
	return 0;
}