#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 100009;

lli arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		lli K;
		lli x_z = 0, y_z = 0;
		map<lli, int> seen;
		int ans = 0;
		cin >> N >> K;
		set<pii> res;
		for (int i = 1; i <= N ; ++i) {
			cin >> arr[i];
			if ((arr[i] == 0) && (!x_z)) { x_z = i; continue; }
			if (!y_z) y_z = i;
			if (arr[i] == 0) continue;
			if ((!(K % arr[i])) && seen[K / arr[i]]) {
				ans = 1;
				res.insert({min(K / arr[i], arr[i]), max(K / arr[i], arr[i])});
			}  
			seen[arr[i]] = i;
		}
		if (K == 0) {
			if (x_z) {
				ans = 1;
				cout << "0 " << y_z << '\n';
			}
		}
		if (res.size()) {
			cout << (*res.begin()).first << ' ' << (*res.begin()).second << '\n';
			ans = 1;
		}
		if (!ans) { cout << "-1\n"; continue; }
	}
	return 0;
}