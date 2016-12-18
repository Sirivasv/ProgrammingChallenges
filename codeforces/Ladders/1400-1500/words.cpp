#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int lowe = 0, uppe = 0;
	for (int i = 0; i < s.size(); ++i) {
		if ((s[i] >= 'a') && (s[i] <= 'z'))
			lowe++;
		else
			uppe++;
	}
	
	if (uppe > lowe)
		for (int i = 0; i < s.size(); ++i)
			cout << (char)toupper(s[i]);
	else
		for (int i = 0; i < s.size(); ++i)
			cout << (char)tolower(s[i]);
	cout << '\n';
	return 0;
}