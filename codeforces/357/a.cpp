#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, b, a;
	cin >> N;
	string s;
	int f = 0;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		cin >> b >> a;
		if (b >= 2400) {
			if (a > b) f = 1;
		}
	}
	if (f)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;	
}