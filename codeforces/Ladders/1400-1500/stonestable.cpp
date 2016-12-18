#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int ans = 0;
	int ccnt = 0;
	char lc = -1;
	for (int i = 0; i < N; ++i) {
		char car;
		cin >> car;
		if (car == lc) {
			ccnt++;
		} else {
			ans += ccnt;
			ccnt = 0;
		}
		lc = car;
	}
	ans += ccnt;
	cout << ans << '\n';
	return 0;
}