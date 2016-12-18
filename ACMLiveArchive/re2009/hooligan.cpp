#include <bits/stdc++.h>
using namespace std;

// Definiciones iniciales.

typedef int Flujo; // Ajustable.

typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef vector<Flujo> Flujo1D;
typedef vector<Flujo1D> Flujo2D;

const Flujo FINF = 1 << 30;

// FLUJO MAXIMO
// Nodos indexados de 0 a n - 1.

struct GrafoFlujo {

    int n; vector<Lista> aristas;
    Flujo2D cap, flujo; Lista padre, dist;
    
    GrafoFlujo(int N) : dist(N), padre(N), aristas(N),
        cap(N, Flujo1D(N)), flujo(N, Flujo1D(N)), n(N) {}

    void AgregarArista(int u, int v, Flujo c) {
        flujo[v][u] += c; // Solo dirigidas!
        cap[u][v] += c, cap[v][u] += c;
        aristas[u].push_back(v);
        aristas[v].push_back(u);
    }

    // Flujo maximo mediante Edmonds-Karp O(VE^2).

    Flujo ActualizarFlujo(int u, Flujo f) {
        int p = padre[u];
        if (p == u) return f;
        f = ActualizarFlujo(p, min(f,
            cap[p][u] - flujo[p][u]));
        flujo[p][u] += f;
        flujo[u][p] -= f;
        return f;
    }

    Flujo AumentarFlujo(int s, int t) {
        fill(padre.begin(), padre.end(), -1);
        queue<int> q; q.push(s); padre[s] = s;
        while (!q.empty()) {
            int u = q.front();
            q.pop(); if (u == t) break;
            for (int i = 0; i < aristas[u].size(); ++i) {
                int v = aristas[u][i];
                if (flujo[u][v] == cap[u][v] ||
                    padre[v] != -1) continue;
                padre[v] = u, q.push(v);
            }
        }
        if (padre[t] == -1) return 0;
        return ActualizarFlujo(t, FINF);
    }

    Flujo EdmondsKarp(int s, int t) {
        Flujo flujo_maximo = 0, f;
        while (f = AumentarFlujo(s, t))
            flujo_maximo += f;
        return flujo_maximo;
    }

    // Flujo maximo mediante Dinic O(V^2E).

    Flujo FlujoBloqueante(int u, int t, Flujo f) {
        if (u == t) return f; Flujo fluido = 0;
        for (int i = 0; i < aristas[u].size(); ++i) {
            if (fluido == f) break; int v = aristas[u][i];
            if (dist[u] + 1 > dist[v]) continue;
            Flujo fv = FlujoBloqueante(v, t,
                min(f - fluido, cap[u][v] - flujo[u][v]));
            flujo[u][v] += fv, fluido += fv;
            flujo[v][u] -= fv;
        }
        return fluido;
    }

    Flujo Dinic(int s, int t) {
        Flujo flujo_maximo = dist[t] = 0;
        while (dist[t] < INT_MAX) {
            fill(dist.begin(), dist.end(), INT_MAX);
            queue<int> q; q.push(s); dist[s] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < aristas[u].size(); ++i) {
                    int v = aristas[u][i];
                    if (flujo[u][v] == cap[u][v] ||
                        dist[v] <= dist[u] + 1) continue;
                    dist[v] = dist[u] + 1, q.push(v);
                }
            }
            if (dist[t] < INT_MAX) flujo_maximo +=
                FlujoBloqueante(s, t, FINF);
        }
        return flujo_maximo;
    }
};

const int MAXN = 50;

int pnts[MAXN], mtr[MAXN][MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, G;
	while (cin >> N >> M >> G) {
		if ((N || M || G) == 0)
			break;
		
		for (int i = 0; i < N;++i) {
			pnts[i] = 0;
			for (int j = 0; j < N; ++j)
				mtr[i][j] = 0;
		}
		
		for (int i = 0; i < G; ++i) {
			int u, v;
			char r;
			cin >> u >> r >> v;
			if (r == '=') {
				pnts[u]++;
				pnts[v]++;
			} else {
				pnts[v] += 2;
			}
			mtr[u][v]++;
			mtr[v][u]++;
		}
		
		for (int i = 1; i < N; ++i) 
			pnts[0] += (M - mtr[0][i]) * 2;
		
		int ok = 1;
		
		for (int i = 1; i < N; ++i)
			if (pnts[i] >= pnts[0])
				ok = 0;
		
		if (!ok) {
			cout << "N\n";
			continue;
		}
		
		GrafoFlujo GF(2000);
		int idm = N;
		int acum = 0;
		// 0 source, 1 -> N - 1 other teams, idm++ matches, last idm sink
		for (int i = 1; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				int lftm = M - mtr[i][j];
				GF.AgregarArista(0, idm, 2 * lftm);
				GF.AgregarArista(idm, i, 2 * lftm);
				GF.AgregarArista(idm, j, 2 * lftm);
				acum += (2 * lftm);
				idm++;
			}
		}
		for (int i = 1; i < N; ++i)
			GF.AgregarArista(i, idm, pnts[0] - 1 - pnts[i]);
		int MF = GF.Dinic(0, idm);
		cout << ((acum == MF)?("Y\n"):("N\n"));
	}
	return 0;
}
