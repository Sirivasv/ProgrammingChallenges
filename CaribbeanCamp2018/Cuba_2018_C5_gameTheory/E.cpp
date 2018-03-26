#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200009;

vector<bool> vis;
vector<int> grafo[MAXN];
vector<int> ordenados;
int grun[MAXN];

void OrdenT(int u ) {
	vis[u] = true;
	for (int v : grafo[u]) {
		if (!vis[v]) OrdenT(v);
	}
	ordenados.push_back(u);
}
 
int Grundy(int u) {
	int mint = 0;
	map<int, int> visto;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		visto[grun[v]] = 1;
		while (visto[mint] == 1) mint++;
	}
	grun[u] = mint;
	return mint;
}
 
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	
	cin >> N >> M;
	
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		grafo[u].push_back(v);
	}
	
	vis = vector<bool>(N + 10);
	for (int i = 0; i < N; ++i) if (!vis[i]) OrdenT(i);
	
	vis = vector<bool>(N + 10);	
	for (int i = 0; i < N; ++i) if (!vis[ordenados[i]]) Grundy(ordenados[i]);
	
	for (int i = 0; i < N; ++i) 
		cout << grun[i] << '\n';
	
	return 0;
}
