#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli INF = 9000000000LL;

set<lli> numb[200];
set<lli> G;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int K, N;
	while (cin >> K >> N) {
		G.clear();
		for (int i = 0; i < K; ++i) {
			numb[i].clear();
			lli val;
			cin >> val;
			lli nval = val;
			while(val < INF) {
				numb[i].insert(val);
				G.insert(val);
				val *= nval;
				//cout << val << '\n';
			}
		} 

		for (int i = 0; i < K; ++i) {
			for (auto it = numb[i].begin(); it != numb[i].end(); ++it) {
				set<lli> NG = G;
				int g = 0;
				for (auto Nit = NG.begin(); Nit != NG.end(); ++Nit) {
					if (((*it) * (*Nit)) < INF) {
						G.insert((*it) * (*Nit));
						if (G.size() > 100009) {
							G.erase(G.end());
						}
					} else {
						g = 1;
						break;
					}
				}
				if (g) break;
			}
		}

		int cnt = 0;
		set<lli> NG = G;
		for (auto Nit = NG.begin(); Nit != NG.end(); ++Nit) {
			cnt++;
			if (cnt == N) {
				cout << (*Nit) << '\n';
				break;
			}
		}
	}

	return 0;
}