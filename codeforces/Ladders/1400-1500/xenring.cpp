#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main() {
	lli N, M;
	cin >> N >> M;
	lli pos = 1LL, ans = 0;
	for (int i = 0; i < M; ++i) {
		lli ai;
		cin >> ai;
		if (pos > ai) {
			ans += (N - pos);
			ans += ai;
		} else 
			ans += (ai - pos);
		pos = ai;
	}
	cout << ans << '\n';
	return 0;
}