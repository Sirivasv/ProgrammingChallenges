#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	while (cin >> T) {
		int cnt = 0, ax;
		for (int i = 0; i < 5; ++i) {
			cin >> ax;
			if (ax == T)
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}