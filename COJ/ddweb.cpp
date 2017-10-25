#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> ter;

const int MAXN = 100009;
const int INF = 2000000000;

int parent[MAXN], MAXMIN;
ter aris[MAXN];

vector<pii> grafo[MAXN];

int Find(int u) { return (parent[u] == u)?(u):(parent[u] = Find(parent[u])); }
void Union(int u, int v) { parent[Find(u)] = Find(v); }  

int dist[MAXN];

void Dijkstra(int S) {
	for (int i = 0; i < MAXN; ++i) dist[i] = INF;
	dist[S] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push({0, S});
	while(!Q.empty()) {
		int u = Q.top().second;
		int p = Q.top().first;
		Q.pop();
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i].first;
			int np = grafo[u][i].second;
			if (np > MAXMIN) np = 0;
			else np = MAXMIN - np;
			if (dist[v] > (p + np)) {
				dist[v] = p + np;
				Q.push({dist[v], v});
			}
		}
	}
}

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);
	int S, SS, N, M;
	cin >> N >> M >> S >> SS;
	for (int i = 1; i <= N; ++i) parent[i] = i;
	for (int i = 0; i < M; ++i) {
		int u, v, p;
		cin >> u >> v >> p;
		grafo[u].push_back({v, p});
		grafo[v].push_back({u, p});
		aris[i] = {p, {u, v}};
	}
	sort(aris, aris + M);
	for (int i = M - 1; i >= 0; --i) {
		int u = aris[i].second.first;
		int v = aris[i].second.second;
		if (Find(u) == Find(v)) continue;
		Union(u, v);
		if (Find(S) == Find(SS)) {
			MAXMIN = aris[i].first;
			break;
		}
	}
	cout << MAXMIN << ' ';
	MAXMIN <<= 1;
	Dijkstra(S);
	cout << dist[SS] << '\n';
	return 0;
}