#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N; 
		cin >> N;
		map<int, int> mp;
		mp[0] = 1;
		int sum = 0, ax, ans = 0;
		for (int i = 0; i < N; ++i) {
			cin >> ax;
			sum += ax;
			ans += mp[sum - 47];
			mp[sum]++;
		}
		cout << ans << '\n';
	}
	return 0;
}