#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, char> pic;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int N;
		map< int, vector<pic> > Xs;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			int xi, xj, yi, yj;
			cin >> xi >> yi >> xj >> yj;
			if (xi == xj) {
				if (yi > yj)
					swap(yi, yj);
				Xs[xi].push_back(pic(yi, 'D')); // Add Q
				Xs[xi].push_back(pic(yj, 'A')); // Quit Q
			} else {
				if(xi > xj)
					swap(xi, xj);
				Xs[xi].push_back(pic(yi, 'B')); // Add H
				Xs[xj].push_back(pic(yi, 'C')); // Quit H
			}
			
		}
		cout << "Case #" << nc << ":\n";
		set<pic> Currp;
		set<pii> pnts;
		for (map< int, vector<pic> >:: iterator it = Xs.begin(); it != Xs.end(); ++it) {
			vector<pic> tmp = (it)->second;
			int lim = tmp.size(); 
			for (int i = 0; i < lim; ++i) {
				/*  'D' // Add Q
					'A' // Quit Q
					'B' // Add H
					'C' // Quit H */
				if ((tmp[i].second == 'D') || (tmp[i].second == 'A'))
					Currp.insert(tmp[i]);
					//assert(Currp.find(tmp[i]) == Currp.end()); si no se cumple lo del assert, se muere
				if (tmp[i].second == 'C') {
					tmp[i].second = 'B';
					Currp.erase(tmp[i]);
					tmp[i].second = 'C';
				}
			}
			//Count int
			int cnt = 0;
			//cout << "**\n";
			for (set<pic>::iterator sit = Currp.begin(); sit != Currp.end(); ++sit) {
				/*  'D' // Add Q
					'A' // Quit Q
					'B' // Add H
					'C' // Quit H */
				//cout << (*sit).second << ' ' << (*sit).first << '\n';
				if ((*sit).second == 'D')
					cnt = 1;
				if ((*sit).second == 'A')
					cnt = 0;
				if (((*sit).second == 'B') && (cnt))
					pnts.insert(pii((it->first), ((*sit).first)));
			}
			
			for (int i = 0; i < lim; ++i) {
				/*  'D' // Add Q
					'A' // Quit Q
					'B' // Add H
					'C' // Quit H */
				if (tmp[i].second == 'B')
					Currp.insert(tmp[i]);
				if ((tmp[i].second == 'D') || (tmp[i].second == 'A')) 
					Currp.erase(tmp[i]);
			}
		}
		for (set<pii>::iterator it = pnts.begin(); it != pnts.end(); ++it)
			cout << (*it).first << ' ' << (*it).second << '\n';
	}
	return 0;
}