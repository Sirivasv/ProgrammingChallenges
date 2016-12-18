#include <bits/stdc++.h>
using namespace std;

int main() {
	int R, G, B;
	cin >> R >> G >> B;
	int tans = -1;
	for (int i = 0; i < 8; ++i) {
		int ans = 0, Ri = R, Gi = G, Bi = B;
		if (i & (1 << 0)) {
			ans += (Ri / 3);
			Ri -= (Ri / 3) * 3;
		}
		if (i & (1 << 1)) {
			ans += (Gi / 3);
			Gi -= (Gi / 3) * 3;
		}
		if (i & (1 << 2)) {
			ans += (Bi / 3);
			Bi -= (Bi / 3) * 3;
		}
		int mint = min(Ri, min(Gi, Bi));
		ans += mint;
		ans += (Ri - mint) / 3;
		ans += (Gi - mint) / 3;
		ans += (Bi - mint) / 3;
		tans = max(tans, ans);
	}
	cout << tans << '\n';
	return 0;
}