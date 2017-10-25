#include <bits/stdc++.h>
using namespace std;

typedef int Dato;
typedef vector<Dato> Vec;
typedef vector<Vec> Mat;
typedef vector<int> Lista;

const Dato INF = 1090000000;
const int MAXN = 109;

struct Flujo {
	int n;
	Lista padre;
	Mat cap, flujo;
	vector<Dato> dist;
	vector<Lista> aristas;
	Flujo(int N) : dist(N), padre(N), aristas(N), cap(N, Vec(N)), flujo(N, Vec(N)), n(N) {}
	
	inline void AgregarArista(int u, int v, Dato c) {
		flujo[v][u] += c;
		cap[u][v] += c, cap[v][u] += c;
		aristas[u].push_back(v);
		aristas[v].push_back(u);
	}
	
	Dato ActualizarFlujo(int u, Dato f) {
        int p = padre[u];
        if (p == u) return f;
        f = ActualizarFlujo(p, min(f, cap[p][u] - flujo[p][u]));
        flujo[p][u] += f;
        flujo[u][p] -= f;
        return f;
    }

    Dato AumentarFlujo(int s, int t) {
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
        return ActualizarFlujo(t, INF);
    }

    Dato EdmondsKarp(int s, int t) {
        Dato flujo_maximo = 0, f;
        while (f = AumentarFlujo(s, t))
            flujo_maximo += f;
        return flujo_maximo;
    }

	inline Dato FlujoBloqueante(int u, int t, Dato f) {
		if (u == t) return f; Dato fluido = 0;
		for (int i = 0; i < aristas[u].size(); ++i) {
			if (fluido == f) break;
			int v = aristas[u][i];
			if (dist[u] + 1 > dist[v]) continue;
			Dato fv = FlujoBloqueante(v, t, min(f - fluido, cap[u][v] - flujo[u][v]));
			flujo[u][v] += fv, fluido += fv;
			flujo[v][u] -= fv;
		}
		return fluido;
	}

	Dato Dinic(int s, int t) {
		Dato flujo_maximo = dist[t] = 0;
		while(dist[t] < INF) {
			fill(dist.begin(), dist.end(), INF);
			queue<int> q; q.push(s); dist[s] = 0;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int i = 0; i < aristas[u].size(); ++i) {
					int v = aristas[u][i];
					if (flujo[u][v] == cap[u][v] || dist[v] <= dist[u] + 1)
						continue;
					dist[v] = dist[u] + 1, q.push(v);
				}
			}
			if (dist[t] < INF) flujo_maximo += FlujoBloqueante(s, t, INF);
		}
		return flujo_maximo;
	}
};

int toQ[MAXN];
Dato capQ[MAXN], sumQ[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N, Q, S;

	cin >> N >> Q >> S;

	Dato sum = 0;

	for (int i = 1; i <= S; ++i) cin >> toQ[i];
	for (int i = 1; i <= Q; ++i) cin >> capQ[i];

	int cnt = 1;
	int lim = N * Q;
	int FD = lim * 2;
	int limT = FD + N + 1;
	
	Flujo myF(limT + 1);

	//cout << limT << " LT\n";

	
	for (int j = 1; j <= N; ++j) {
		for (int i = 1; i <= Q; ++i) {
			//AGREGAR ARISTA DE nodo a nodo2 con capQ
			int nodo = (Q * (j - 1)) + i;
			int nodo2 = nodo + lim;
			myF.AgregarArista(nodo, nodo2, capQ[i]);
			if (j != 1) {
				int pnodo = (Q * (j - 2)) + i;
				int pnodo2 = pnodo + lim;
				myF.AgregarArista(pnodo2, nodo, capQ[i]);
				//cout << "PREVN: " << prevn << " -- " << INF << "-->" << "NODO: " << nodo << '\n';
			}
			//cout << "NODO: " << nodo << " -- " << capQ[i] << "-->" << "NODO2: " << nodo2 << '\n'; 
		}
	}

	for (int i = 1; i <= N; ++i) {
		Dato diCap;
		cin >> diCap;
		for (int j = 1; j <= S; ++j) {
			Dato siCap;
			cin >> siCap;
			sum += siCap;
			int nodo = (Q * (i - 1)) + toQ[j];
			int nodo2 = nodo + lim;
			//AGREGAR ARISTA DE S A nodo con siCap
			myF.AgregarArista(0, nodo, siCap);
			//cout << "S: " << 0 << "-- " << sumQ[j] << "-->" << "NODO: " << nodo << '\n';
			//AGREGAR ARISTA DE nodo2 A ? con INF	
		}
		for (int j = 1; j <= Q; ++j) {
			int nodo = (Q * (i - 1)) + j;
			int nodo2 = nodo + lim;
			myF.AgregarArista(nodo2, FD + i, diCap);
			//cout << "NODO2: " << nodo2 << " -- " << INF << "-->" << "FDi: " << (FD + i) << '\n';
		}
		//AGREGAR ARISTA DE ? A T con diCap
		myF.AgregarArista(FD + i, limT, diCap);
		//cout << "NODO2: " << (FD + i) << " -- " << diCap << "-->" << "T: " << (limT) << '\n';
	}

	Dato res = myF.EdmondsKarp(0, limT);

	//cout << res << ' ' << sum << '\n';
	if (sum == res) cout << "possible\n";
	else cout << "impossible\n";

	return 0;
}