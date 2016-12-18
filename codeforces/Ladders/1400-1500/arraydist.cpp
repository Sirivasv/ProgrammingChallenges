#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	map<int, int> last_pos;
	set<int> alive_pos;
	int N, K, ans = 1000000, l, r;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		int nu;
		cin >> nu;
		alive_pos.erase(last_pos[nu]);
		alive_pos.insert(i);
		last_pos[nu] = i;
		if (K == alive_pos.size()) {
			int m = (*alive_pos.rbegin()) -  (*alive_pos.begin()) + 1; 
			if (m < ans) {
				ans = m;
				l = (*alive_pos.begin());
				r = (*alive_pos.rbegin());
			}
			alive_pos.erase(alive_pos.begin());
		}
	}
	if (ans == 1000000)
		cout << "-1 -1\n";
	else
		cout << l << ' ' << r << '\n';
	return 0;
}