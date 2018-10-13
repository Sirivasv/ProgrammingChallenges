#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;
typedef pair<pii, pii> zer;

const int MAXN = 100009;

int N, M;
lli C;

inline lli Abs(lli xi) { return ((xi < 0)?(-xi):(xi));}

inline lli Dist(pii pa, pii pb) { return (Abs(pa.first - pb.first) + 1LL); }

inline int matsSet(const vector<zer> &vtr) {

	int mats = 1;
	int prev = 0;

	for (int i = 1; i < vtr.size(); i++) {
		if (vtr[prev].second.first < vtr[i].second.first) { 
			if (Dist(vtr[prev].second, vtr[i].second) >=  ((vtr[prev].first.second * vtr[prev].first.second) + (vtr[i].first.second * vtr[i].first.second) + C)  ) {
				prev = i;
				mats++;
			}
		}
	}

	return mats;
}

inline int matsSet2(const vector<zer> &vtr) {

	int mats = 1;
	int prev = vtr.size() - 1;

	for (int i = vtr.size() - 2; i >= 0; i--) {
		if (vtr[prev].second.first > vtr[i].second.first) { 
			if (Dist(vtr[prev].second, vtr[i].second) >=  ((vtr[prev].first.second * vtr[prev].first.second) + (vtr[i].first.second * vtr[i].first.second) + C)  ) {
				prev = i;
				mats++;
			}
		}
	}

	return mats;
}


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int T;
	ifstream fin("bishops.in");
	fin >> T;
	// cin >> T;

	for (int nc = 0; nc < T; ++nc) {

		fin >> N >> M >> C;
		// cin >> N >> M >> C;

		map< lli, vector<zer> > FD, SD;

		for (int i = 0; i < M; ++i) {

			zer pnt;
			// cin >> pnt.second.first >> pnt.second.second >> pnt.first.second;
			fin >> pnt.second.first >> pnt.second.second >> pnt.first.second;
			
			pnt.first.first = (pnt.first.second * pnt.first.second) + pnt.second.first;
			
			lli xi = pnt.second.first - pnt.second.second;
			FD[xi].push_back(pnt);
			
				xi = pnt.second.first + pnt.second.second;
			SD[xi].push_back(pnt);

		}

		int mats = 0;
		for (map< lli, vector<zer> >::iterator it = FD.begin(); it != FD.end(); it++) {
			sort((it->second).begin(), (it->second).end());
			mats = max(mats, matsSet(it->second));
			mats = max(mats, matsSet2(it->second));
		}

		for (map< lli, vector<zer> >::iterator it = SD.begin(); it != SD.end(); it++) {
			sort((it->second).begin(), (it->second).end());
			mats = max(mats, matsSet(it->second));
			mats = max(mats, matsSet2(it->second));
		}

		cout << mats << '\n';
	}

	return 0;
}