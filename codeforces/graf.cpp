#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

vector<int> grafo[MAXN];
int NColor[MAXN];
bitset<MAXN> vis;
char Procesado[MAXN];
bool HayCiclo;

void AgregarArista(int u, int v) {
	grafo[u].push_back(v);
	grafo[v].push_back(u);
}

void VisDFS(int u, int color) {
	vis[u] = 1;
	NColor[u] = color;
	
	Procesado[u] = 'G';
	
	//cout << u << '\n';
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (!vis[v])
			VisDFS(v, color);
		else if (Procesado[u] == 'G')
			HayCiclo = true;
	}
	
	Procesado[u] = 'N';
	
}

void VisBFS(int o, int color) {
	vis[o] = 1;
	NColor[o] = color;
	queue<int> Q;
	Q.push(o);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i];
			if (!vis[v]) {
				vis[v] = 1;
				NColor[v] = color;
				Q.push(v);
			}	
		}
	}
}

int main() {
	int N, M; // Nodos y Aristas
	int nc = 1;
	while (cin >> N >> M) {
		
		if ((N == 0) && (M == 0))
			break;
		
		HayCiclo = false;
		for (int i = 0; i < N; ++i) {
			grafo[i].clear();
			NColor[i] = 0;
			Procesado[i] = 'B';
		}
		
		for (int i = 0; i < M; ++i) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			AgregarArista(u, v);
		} 
		
		vis.reset();
		int color = 1;
		for (int i = 0; i < N; ++i)
			if (!vis[i])
				VisDFS(i, color++);
		
		vis.reset();
		
		color = 1;
		for (int i = 0; i < N; ++i)
			if (!vis[i])
				VisBFS(i, color++);
		
		cout << "Case " << (nc++) << ": " << (color - 1) << '\n';
		
	}
	return 0;
}