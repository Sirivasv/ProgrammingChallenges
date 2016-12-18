#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	int lim = s.size();
	int pos;
	for (int i = 0; i < lim; ++i) {
		if (s[i] == 'G') {
			s[i] = '.';
			pos = i;
			break;
		}
	}
	int ok = 0;
	//der
	for (int i = pos; i < lim; i += K) {
		if (s[i] == '#')
			break;
		if (s[i] == 'T') {
			ok = 1;
			break;
		}
	}
	//izq
	for (int i = pos; i >= 0; i -= K) {
		if (s[i] == '#')
			break;
		if (s[i] == 'T') {
			ok = 1;
			break;
		}
	}
	
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}