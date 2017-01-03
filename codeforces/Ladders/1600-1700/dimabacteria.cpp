#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;
const int MAXK = 505;
const lli INF = (1LL << 61);

int parent[MAXN];

int Find(int u) { return ((parent[u] == u)?(u):(parent[u] = Find(parent[u]))); }

void Union(int u, int v) { parent[Find(u)] = Find(v); }

vector<int> tipolist[MAXK];
int tipo[MAXN];
lli Dist[MAXK][MAXK];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, K; 
	
	for (int i = 0; i < MAXK; ++i)
		for (int j = 0; j < MAXK; ++j)
			Dist[i][j] = INF;
	
	cin >> N >> M >> K;

	int cnt = 0;
	for (int i = 0; i < K; ++i) {
		int ci;
		cin >> ci;
		int lim = cnt + ci;
		for (int j = cnt; j < lim; ++j) {
			parent[j] = j;
			tipo[j] = i;
			tipolist[i].push_back(j);
		}
		cnt = lim;
	}
	
	for (int i = 0; i < M; ++i) {
		int u, v;
		lli ci;
		cin >> u >> v >> ci;
		u--; v--;
		if (ci == 0) Union(u, v);
		Dist[tipo[u]][tipo[v]] = min(Dist[tipo[u]][tipo[v]], ci);
		Dist[tipo[v]][tipo[u]] = min(Dist[tipo[v]][tipo[u]], ci);
	}
	
	int ok = 1;
	
	for (int i = 0; i < K; ++i) {
		int lim = tipolist[i].size();
		int pr = Find(tipolist[i][0]);
		for (int j = 0; j < lim; ++j)
			if (Find(tipolist[i][j]) != pr) ok = 0;
		if (ok) Dist[i][i] = 0;
	}
	
	if (ok) {
		cout << "Yes\n";
		
		for (int k = 0; k < K; ++k)
			for (int i = 0; i < K; ++i)
				for (int j = 0; j < K; ++j) 
					Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
		
		for (int i = 0; i < K; ++i) {
			for (int j = 0; j < K; ++j) {
				if (j) cout << ' ';
				cout << ((Dist[i][j] != INF)?(Dist[i][j]):(-1));
			}
			cout << '\n';
		}	
	
	} else cout << "No\n";
	
	return 0;
}