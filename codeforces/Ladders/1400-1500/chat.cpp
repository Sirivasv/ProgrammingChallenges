#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	string pala = "hello";
	int id = 0, ok = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == pala[id])
			id++;
		if (id == 5) {
			ok = 1;
			break;
		}
	}
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}