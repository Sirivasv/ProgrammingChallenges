#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const int MAXN = 70;

vll lvl[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		
		ll mats = 0;
		
		for (int i = 0; i < N; ++i) {
			ll l;
			cin >> l;
			mats = max(mats, l);
			lvl[l].push_back(0);
		}
		
		ll pma = 1LL, nma = 1LL;
		
		for (int i = mats; i > 0; --i) {
				
			int lim = lvl[i].size();
			
			for (int j = 1; j < lim; j += 2) {
				ll vall = (lvl[i][j - 1]) ? lvl[i][j - 1] : pma;
				ll valr = (lvl[i][j]) ? lvl[i][j] : pma;
				lvl[i - 1].push_back(vall + valr);
				nma = max(nma, max(vall, valr));
			}
			
			lvl[i].clear();
			pma = nma;
			nma = 1LL;
		}
	
		cout << lvl[0][0] << '\n';
		lvl[0].clear();
	}
	return 0;
}