#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, twe = 0, fif = 0;
	cin >> N;
	int ok = 1;
	for (int i = 0; i < N; ++i) {
		int p;
		cin >> p;
		if (p == 100) {
			if ((twe) && (fif)) {
				fif--;
				twe--;
			} else if (twe >= 3)
				twe -= 3;
			else {
				ok = 0;
				break;
			}
		} else if (p == 50) {
			if (twe)
				twe--;
			else {
				ok = 0;
				break;
			}
			fif++;
		} else
			twe++;
	}
	cout << ((ok)?("YES\n"):("NO\n"));
	return 0;
}