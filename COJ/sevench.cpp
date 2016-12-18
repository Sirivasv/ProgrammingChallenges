#include <bits/stdc++.h>
using namespace std;

// Definiciones iniciales.

typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef pair<double, int> pdi;

// EMPAREJAMIENTO BIPARTITO
// Nodos indexados de 0 a n - 1.

struct Bipartito {

    int n; Lista pareja;
    vector<Lista> aristas;
    vector<bool> lado, visitado;

    Bipartito(int N) : lado(N), pareja(N),
        visitado(N), aristas(N), n(N) {}

    void AgregarArista(int u, int v) {
        aristas[u].push_back(v);
        aristas[v].push_back(u);
    }

    void AgregarIzq(int u) { lado[u] = true; }
    void AgregarDer(int u) { lado[u] = false; }

    int CaminoIncremental(int u) {
        visitado[u] = true;
        for (int i = 0; i < aristas[u].size(); ++i)
            if (pareja[aristas[u][i]] == -1) 
                return pareja[aristas[u][i]] = u;
        for (int i = 0; i < aristas[u].size(); ++i) {
            int v = aristas[u][i];
            if (visitado[pareja[v]]) continue;
            if (CaminoIncremental(pareja[v]) != -1)
                return pareja[v] = u;
        }
        return -1;
    }

    vector<Par> MaxEmparejamiento() {
        fill(pareja.begin(), pareja.end(), -1);
        for (int i = 0; i < n; ++i) {
            if (!lado[i]) continue; CaminoIncremental(i);
            fill(visitado.begin(), visitado.end(), false);
        }
        vector<Par> pares;
        for (int i = 0; i < n; ++i)
            if (!lado[i] && pareja[i] != -1)
                pares.push_back(Par(pareja[i], i));
        return pares; // Cardinalidad = pares.size()
    }
	
};

const int MAXN = 5009;

pdi Pi[MAXN];
vector<int> Couple[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N, M;
	
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> Pi[i].first >> tmp;
		Pi[i].first *= -1.0;
		Pi[i].second = i;
		Couple[i] = vector<int>(tmp, 0);
		for (int j = 0; j < tmp; ++j) {
			cin >> Couple[i][j];
			Couple[i][j]--;
		}
	}
	
	sort(Pi, Pi + N);
	
	Bipartito Bp(N + M);
	
	for (int i = 0; i < N; ++i) {
		Bp.AgregarIzq(i);
		for (int j = 0; j < Couple[Pi[i].second].size(); ++j) {
			Bp.AgregarArista(i, Couple[Pi[i].second][j] + N);
			Bp.AgregarDer(Couple[Pi[i].second][j] + N);
		}
	}
	
	vector<Par> ME = Bp.MaxEmparejamiento();
	
	double sum = 0;
	
	for (int i = 0; i < ME.size(); ++i)
		sum += log10(Pi[ME[i].first].first * (-1.0));
	cout << ((int)floor(sum) + 1) << '\n';
	
	return 0;
}
