#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20009;
const int MAXR = 105;

vector<int> grafo[MAXN];

int pareja[MAXN];
int visitado[MAXN], lcv;

int CaminoIncremental(int u) {
	visitado[u] = lcv;
	int lim = grafo[u].size();
	
	for (int i = 0; i < lim; ++i)
		if (pareja[grafo[u][i]] == -1)
			return pareja[grafo[u][i]] = u;
		
	for (int i = 0; i < lim; ++i) {
		int v = grafo[u][i];
		if (visitado[pareja[v]] == lcv) continue;
		if (CaminoIncremental(pareja[v]) != -1)
			return pareja[v] = u;
	}
	
	return -1;
}

int MCBM(const vector<int>& l, const vector<int>& r) {
	int n = l.size() + r.size();
	fill(pareja, pareja + n, -1);
	int lim = l.size();
	
	for (int i = 0; i < lim; ++i) {
		++lcv;
		CaminoIncremental(l[i]);
	}
	
	int parejas = 0;
	lim = r.size();
	
	for (int i = 0; i < lim; ++i)
		if (pareja[r[i]] != -1)
			parejas++;
	
	return parejas;
}

int pmatr[MAXR][MAXR];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	while (cin >> N) {
		char aux;
		int actr = 0, mny = 0;
		vector<int> l, r;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				pmatr[i][j] = -1;
			
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> aux;
				if ((aux == 'X') && (mny)) {
					l.push_back(actr++);
					mny = 0;
				} else if (aux == '.'){
					pmatr[i][j] = actr;
					mny++;
				}
				
			}
			if (mny) {
				l.push_back(actr++);
				mny = 0;
			}

		}
		
		for (int j = 0; j < N; ++j) {
			for (int i = 0; i < N; ++i) {
				int val = pmatr[i][j];
				if ((val == -1) && (mny)) {
					r.push_back(actr++);
					mny = 0;
				} else if (val != -1){
					grafo[val].push_back(actr);
					grafo[actr].push_back(val);
					mny++;
				}
			}
			if (mny) {
				r.push_back(actr++);
				mny = 0;
			}
		}
	
		cout << MCBM(l, r) << '\n';
		for (int i = 0; i <= actr; ++i)
			grafo[i].clear();
	}
	
	return 0;
}