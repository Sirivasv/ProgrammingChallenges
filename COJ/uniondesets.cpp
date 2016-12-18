#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T, N, ax;
	cin >> T;
	set<int> mys;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		while (N--) {
			cin >> ax;
			mys.insert(ax);
		}
	}
	cout << mys.size() << '\n';
	return 0;
}