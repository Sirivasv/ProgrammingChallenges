#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, mint, mats, p;
	cin >> N;
	cin >> p;
	mint = mats = p;
	int ans = 0;
	for (int i = 1; i < N; ++i) {
		cin >> p;
		if (p > mats) {
			mats = p;
			ans++;
		}
		if (p < mint) {
			mint = p;
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}