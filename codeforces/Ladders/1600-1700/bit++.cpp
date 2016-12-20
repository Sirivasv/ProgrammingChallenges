#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	int xi = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		if ((s[0] == '+') || (s[2] == '+')) xi++;
		else xi--;
	}
	cout << xi << '\n';
	return 0;
}