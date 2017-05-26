#include <bits/stdc++.h>
using namespace std;

void abrev(string s, int l) {
	cout << s[0] << (l - 2) << s[l - 1] << '\n';
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		int l = s.size();
		if (l > 10) abrev(s, l);
		else cout << s << '\n';
	}
	return 0;
}