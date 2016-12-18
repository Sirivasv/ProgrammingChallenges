#include <bits/stdc++.h>

using namespace std;

typedef long long lli;


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		priority_queue< lli, vector<lli>, greater<lli> > pq;
		for (int i = 0; i < N; ++i) {
			lli tmp;
			cin >> tmp;
			pq.push(tmp);
		}
		lli mayor = 0;
		while (pq.size() >= 2) {
			lli f = pq.top();
			pq.pop();
			lli s = pq.top();
			pq.pop();
			if (f == s)
				pq.push(f + s);
			else {
				mayor = max(mayor, f);
				pq.push(s);
			}
		}
		while (pq.size()) {
			mayor = max(mayor, pq.top());
			pq.pop();
		}
		cout << mayor << '\n';
	}
	return 0;
}