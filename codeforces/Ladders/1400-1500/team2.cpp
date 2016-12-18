#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int ans = 0;
	for(int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = 0; j < 3; ++j) {
			int v;
			cin >> v;
			cnt += v;
		}
		if (cnt >= 2)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}