#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1009;
int G[MAXN], N, a, sum, lim, tp;

int main() {
	cin.tie(); ios_base::sync_with_stdio(0);
	cin >> N;
	priority_queue<int> Q;
	lim = (N >> 1) + 1;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		a = (a >> 1) + 1;
		if (Q.size() < lim) {
			sum += a;
			Q.push(a);
		} else {
			tp = Q.top();
			if (a < tp) {
				Q.pop();
				Q.push(a);
				sum -= tp;
				sum += a;
			}
		}
	}
	cout << sum << '\n';
	return 0;
}