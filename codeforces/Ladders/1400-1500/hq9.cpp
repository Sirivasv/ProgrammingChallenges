#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ok = 0;
	for (int i = 0; i < s.size(); ++i)
		if ((s[i] == 'H') || (s[i] == 'Q') || (s[i] == '9'))
			ok = 1;
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}