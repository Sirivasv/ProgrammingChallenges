#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 500;

int Adj[MAXN][MAXN];
set<pii> Edif[MAXN];


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 0; nc < T; ++nc) {
		int N, F, M, Nc = 1; 
		
		cin >> N >> F >> M;
		
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				Adj[i][j] = 1000000000;
				if (i == j)
					Adj[i][j] = 0;
			}
		}
		
		map<pii, int> ptoN;
		
		//Nodes from 0, to N - 1 -> floor 1 in edif 
		
		for (int i = 1; i <= N; ++i) {
			Edif[i].clear();
			Edif[i].insert(pii(1, i));
			ptoN[pii(i, 1)] = Nc++;
			Adj[((i - 1) % N) + 1][(i % N ) + 1] = 1;
			Adj[(i % N ) + 1][((i - 1) % N) + 1] = 1;
			//cout << "U: " << (i % N ) + 1 << " V: " << ((i - 1) % N) + 1 << '\n';
		}
		
		//Add edges between nodes of interest
		
		for (int i = 0; i < M; ++i) {
			int pi, fi, pj, fj, ti;
			cin >> pi >> fi >> pj >> fj >> ti;
			pii ps(pi, fi), pe(pj, fj);
			if (!ptoN.count(ps))
				ptoN[ps] = Nc++;
			if (!ptoN.count(pe))
				ptoN[pe] = Nc++;
			Edif[pi].insert(pii(fi, ptoN[ps]));
			Edif[pj].insert(pii(fj, ptoN[pe]));
			Adj[ptoN[pe]][ptoN[ps]] = ti; 
			Adj[ptoN[ps]][ptoN[pe]] = ti;
			
			//cout << pi << ' ' << fi << ' ' << pj << ' ' << fj << '\n';
			//cout << ptoN[ps] << ' ' << ptoN[pe] << '\n';
			
			
		}
		
		//Add Nodes on each building
		for (int i = 1; i <= N; ++i) {
			//cout << "**\n";
			for (set<pii>::iterator it = Edif[i].begin(); it != Edif[i].end(); it++) {
				set<pii>::iterator itn = it;
				itn++;
				if (itn == Edif[i].end())
					continue;
				Adj[it->second][itn->second] = max(it->first, itn->first) - min(it->first, itn->first);
				Adj[itn->second][it->second] = max(it->first, itn->first) - min(it->first, itn->first);
				//cout << "U2: " << it->second << " V2: " << itn->second << '\n';
			}
			
		}
		
		//floyd
		
		for (int k = 1; k < Nc; ++k) {
			for (int i = 1; i < Nc; ++i) {
				for (int j = 1; j < Nc; ++j) {
					Adj[i][j] = min(Adj[i][j], Adj[i][k] + Adj[k][j]);
				}
			}
		}
		
		/*for (int i = 1; i < Nc; ++i) {
			cout << "I: " << i << '\n';
			for (int j = 1; j < Nc; ++j) {
				cout << Adj[i][j] << ' ';
			}
			cout << '\n';
		}*/
		
		int Q;
		cin >> Q;
		for (int i = 0; i < Q; ++i) {
			int pi, fi, pj, fj;
			cin >> pi >> fi >> pj >> fj;
			//ans without mb
			int ans = 1 << 30;
			if (pi == pj)
				ans = max(fi, fj) - min(fi, fj);
			else
				ans = (fi - 1) + (fj - 1) + (min(max(pi, pj) - min(pi, pj), N - (max(pi, pj) - min(pi, pj))));
			//cout << "** " << ans << '\n';
			set<pii>::iterator pli = Edif[pi].end(), pui = Edif[pi].end(), plj = Edif[pj].end(), puj = Edif[pj].end();
			
			pui = Edif[pi].upper_bound(pii(fi, -1));
			
			if (pui != Edif[pi].begin()) {
				pli = pui;
				pli--;
			}
			
			puj = Edif[pj].upper_bound(pii(fj, -1));
			if (puj != Edif[pj].begin()) {
				plj = puj;
				plj--;
			}
			
			//Try pi to pui
			if (pui != Edif[pi].end()) {
				int pans = max(fi, pui->first) - min(fi, pui->first);
				if (puj != Edif[pj].end()) { //try pui to puj
					pans += Adj[pui->second][puj->second];
					pans += max(fj, puj->first) - min(fj, puj->first);
					ans = min(ans, pans);
				} 
				
				pans = max(fi, pui->first) - min(fi, pui->first);
				if (plj != Edif[pj].end()){ //try pui to plj
					pans += Adj[pui->second][plj->second];
					pans += max(fj, plj->first) - min(fj, plj->first);
					ans = min(ans, pans);
				}
				
			}
			//try pi to pli
			if (pli != Edif[pi].end()) {
				int pans = max(fi, pli->first) - min(fi, pli->first);
				if (puj != Edif[pj].end()) { //try pui to puj
					pans += Adj[pli->second][puj->second];
					pans += max(fj, puj->first) - min(fj, puj->first);
					ans = min(ans, pans);
				} 
				
				pans = max(fi, pli->first) - min(fi, pli->first);
				if (plj != Edif[pj].end()){ //try pui to plj
					pans += Adj[pli->second][plj->second];
					pans += max(fj, plj->first) - min(fj, plj->first);
					ans = min(ans, pans);
				}
				
			}
			
			cout << ans << '\n';
		}
	}
	return 0;
}