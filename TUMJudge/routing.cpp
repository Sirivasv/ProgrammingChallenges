#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int INF = (1 << 30);
const int MAXN = 109;
const int MAXNN = 10009;

set<int> banned[MAXNN];
int idb;
int proctime[MAXN];
int Dist[MAXN];
int vis[MAXN][MAXN];
vector<pii> grafo[MAXN];

int N, M;

void Dijkstra() {
	priority_queue< piii, vector<piii>, greater<piii> > Q;
	Dist[0] = proctime[0];
	Q.push(piii(proctime[0], pii(0, -10)));
	while(!Q.empty()) {
		int u = Q.top().second.first;
		int p = Q.top().first;
		int ld = Q.top().second.second;
		Q.pop();
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i].first;
			int idi = grafo[u][i].second;
			if (banned[idi].find(ld) != banned[idi].end())
				continue;
			if ((!vis[v][u]) || (Dist[v] > (p + proctime[v])) ){
				vis[v][u] = 1;
				Dist[v] = min(Dist[v], p + proctime[v]);
				Q.push(piii(p + proctime[v], pii(v, u)));
			}
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		Dist[i] = INF;
	for (int i = 0; i < N; ++i) {
		cin >> M >> proctime[i];
		for (int j = 0; j < M; ++j) {
			int ml, v;
			cin >> ml >> v;
			v--;
			for (int k = 0; k < ml; ++k) {
				int aux;
				cin >> aux;
				aux--;
				banned[idb].insert(aux);
			}
			grafo[i].push_back(pii(v, idb));
			idb++;
		}
	}
	Dijkstra();
	if (Dist[N - 1] == INF)
		cout << "impossible\n";
	else
		cout << Dist[N - 1] << '\n';
	return 0;
}