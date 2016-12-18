//2959
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
int LIS (vi &v) {
	vpii best;
	vi dad(v.size(), -1);
	for (int i = 0; i < v.size(); i++) {
		pii item = pii(v[i], i);
		auto it = lower_bound(best.begin(), best.end(), item);
		if (it == best.end()){
			dad[i] = ((best.size() == 0)? -1: best.back().second);
			best.push_back(item);
		} else {
		    if ((it->first) == item.first) continue;
		    dad[i] = dad[it->second];
			*it = item;
		}
	}
	int r = 0;
	int i = best.back().second;
	while (i>=0){
		r++;
		i = dad[i];
	}
	return r;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
	int nc, N, a;
	cin >> nc;
	while (nc--) {
	    cin >> N;
	    vi v(N);
	    for(int i = 0; i < N; i++) cin >> v[i];
        cout << LIS(v) << '\n';
    }
	return 0;
}