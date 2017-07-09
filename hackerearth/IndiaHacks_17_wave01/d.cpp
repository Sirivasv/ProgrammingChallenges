#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;

	cin >> T;
	for (int nt = 0; nt < T; ++nt) {
		lli N, S, X;
		cin >> N >> S >> X;
		if (N == 1) {
			if (S == X) cout << "Yes\n";
			else cout << "No\n";
		} else {
			if (((S - X) % (N - 1LL)) == 0LL) cout << "Yes\n";
			else cout << "No\n";
		}
	}

	return 0;
}