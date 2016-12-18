#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// Definiciones iniciales
typedef pair<int, int> Arista;
const int INF = 1 << 30;
const int MAXN = 10009;
vi grafo[MAXN], puentes[MAXN];
int numeracion;
int low[MAXN], num[MAXN], punto_art[MAXN];
set<Arista> Puentesp;
int parent[MAXN];

// Detecta los puentes y puntos de articulacion en
// un grafo bidireccional. Indices de 0 a n - 1.
void PuntosArtPuentes_(int u, int p) {
    int hijos = 0;
    low[u] = num[u] = ++numeracion;
    for (int i = 0; i < grafo[u].size(); ++i) {
        int v = grafo[u][i];
        if (v == p) continue;
        if (!num[v]) {
            ++hijos;
            PuntosArtPuentes_(v, u);
            if (low[v] > num[u]) {
                puentes[u].push_back(v);
                puentes[v].push_back(u);
            }
            low[u] = min(low[u], low[v]);
            punto_art[u] |= low[v] >= num[u];
        } else low[u] = min(low[u], num[v]);
    }
    if (p == -1) punto_art[u] = hijos > 1;
}

void PuntosArtPuentes(int n) {
    numeracion = 0;
    fill(num, num + n, 0);
    fill(low, low + n, 0);
	fill(punto_art, punto_art + n, 0);
    for (int i = 0; i < n; ++i)
		puentes[i].clear();
    for (int i = 0; i < n; ++i)
        if (!num[i]) PuntosArtPuentes_(i, -1);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < puentes[i].size(); ++j)
            Puentesp.insert(Arista(i, puentes[i][j]));
}

void Limpia(int N) {
	for (int i = 0; i < N; ++i)
		grafo[i].clear();
	for (int i = 0; i < N; ++i)
		parent[i] = i;
	Puentesp.clear();
}

int Find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = Find(parent[u]);
}

bool MismoConjunto(int u, int v) {
	return Find(u) == Find(v);
}

void Union(int u, int v) {
	if (MismoConjunto(u, v))
		return;
	parent[Find(u)] = Find(v);
}

void FillUF(int N) {
	//for (set<Arista>::iterator it = Puentesp.begin(); it != Puentesp.end(); it++)
		//cout << (*it).first << ' ' << (*it).second << " **\n";
	for (int u = 0; u < N; ++u) {
		for (int j = 0; j < grafo[u].size(); ++j) {
			int v = grafo[u][j];
			//cout << u << ' ' << v << "**\n";
			//cout << (*Puentesp.find(Arista(u, v))).first << ' ' << (*Puentesp.find(Arista(u, v))).second << '\n';
			//cout << (*Puentesp.end()).first << ' ' << (*Puentesp.end()).second << '\n';
			if (((Puentesp.find(Arista(u, v)) != Puentesp.end()) || (Puentesp.find(Arista(v, u)) != Puentesp.end())) && (punto_art[v] || punto_art[u]))
				//cout << u << ' ' << v << '\n';
				Union(u, v);
	
			//if (punto_art[v]) 
				//Union(u, v);
		}
	}
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, Q;
	while (cin >> N >> M >> Q) {
		if (!(N + M + Q))
			break;
		Limpia(N);
		int u, v;
		for(int i = 0; i < M; ++i) { 
			cin >> u >> v;
			u--, v--;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		PuntosArtPuentes(N);
		FillUF(N);
		for (int i = 0; i < Q; ++i) {
			cin >> u >> v;
			u--, v--;
			//cout << u << ' ' << v << " ++\n";
			cout << ((MismoConjunto(u, v))?('Y'):('N')) << '\n';
		}
		cout << "-\n";
	}
	return 0;
}