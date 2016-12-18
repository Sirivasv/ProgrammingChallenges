#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		if (s.size() <= 10)
			cout << s << '\n';
		else {
			cout << s[0] << (s.size() - 2) << s[s.size() - 1] << '\n';
		}
	}
	return 0;
}