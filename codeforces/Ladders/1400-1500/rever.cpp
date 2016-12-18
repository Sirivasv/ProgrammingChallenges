#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s, ss;
	cin >> s >> ss;
	reverse(s.begin(), s.end());
	cout << ((s == ss)?("YES\n"):("NO\n"));
	return 0;
}