//Div 1 C, Acumulados en Arbol
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;
const int MAXP = 32;

vector<int> grafo[MAXN];
int p[MAXN][MAXP], h[MAXN], acum[MAXN];
pii aristas[MAXN];

void Enraizar(int u, int parent) {
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v != parent) {
			h[v] = h[u] + 1; p[v][0] = u;
			for (int j = 1; j < MAXP; ++j) p[v][j] = p[p[v][j - 1]][j - 1];
			Enraizar(v, u); 
		}
	}
}

int parent(int u, int pid) {
	for (int i = 0; i < MAXP; ++i) if (pid & (1 << i)) u = p[u][i]; 
	return u;
}

int LCA(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	u = parent(u, h[u] - h[v]);
	for (int i = MAXP - 1; i >= 0; --i) if (p[u][i] != p[v][i]) {
		u = p[u][i];
		v = p[v][i];
	}
	return ((u == v)?(u):(p[u][0]));
}

int Sum(int u, int parent) {
	for (int i = 0; i < grafo[u].size(); ++i){
		int v = grafo[u][i];
		if (v != parent) acum[u] += Sum(v, u);
	}
	return acum[u];
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
		aristas[i] = pii(u, v);
	}
	Enraizar(1, -1);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int u, v;
		cin >> u >> v;
		acum[u]++;
		acum[v]++;
		acum[LCA(u, v)] -= 2;
	}
	Sum(1, -1);
	for (int i = 0; i < N - 1; ++i) {
		if (i) cout << ' ';
		if (h[aristas[i].first] > h[aristas[i].second])
			cout << acum[aristas[i].first];
		else
			cout << acum[aristas[i].second];
	}
	return 0;
}