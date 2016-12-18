#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll F(ll N) {
	return (((N + 1) / 2LL) + (((N - (((N - 1) / 3LL) + 1)) + 1LL + (N & 1LL)) / 2LL));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	ll N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << F(N) << '\n';
	}
	return 0;
}