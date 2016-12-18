#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair <char, int> pci;
typedef pair<int, pci> ter;


const int MAXN = 1009;

pii Stars[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		priority_queue<ter, vector<ter>, greater<ter> > pq;
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> Stars[i].first >> Stars[i].second;
			pq.push(ter(Stars[i].first, pci('i', i)));
		}
		int ans = 0, strs = 0;
		while (!pq.empty()) {
			if (strs >= pq.top().first) {
				if (pq.top().second.first == 'i') {
					int ni = pq.top().second.second;
					pq.pop();
					pq.push(ter(Stars[ni].second, pci('f', ni)));
					strs++;
				} else {
					strs += 2;
					pq.pop();
				}
			} else {
				ans += (pq.top().first - strs);
				strs = pq.top().first;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}