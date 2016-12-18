#include <bits/stdc++.h>
using namespace std;

// Definiciones iniciales.

typedef int Flujo; // Ajustable.

typedef vector<int> Lista;
typedef pair<int, int> Par;

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

const int MAXN = 105;
vector<int> Heredity[MAXN];
bitset<MAXN> Has;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int P, Q;
	while (cin >> P >> Q) {
		for (int i = 0; i < P; ++i)
			Heredity[i].clear();
		int flag = 0;
		for (int i = 0; i < P; ++i) {
			int lg = 0, many = 0;
			cin >> lg;
			for (int j = 0; j < lg; ++j) {
				int tmp;
				cin >> tmp;
				tmp--;
				Heredity[i].push_back(tmp);
				many++;
			}
			if (many == P)
				flag = 1;
		}
		for (int i = 0; i < Q; ++i) {
			int lg;
			cin >> lg;
			if (lg == 0) {
				if (flag)
					cout << "N\n";
				else 
					cout << "Y\n";
			} else {
				Has.reset();
				for (int j = 0; j < lg; ++j) {
					int tmp;
					cin >> tmp;
					tmp--;
					Has[tmp] = 1;
				}
				Bipartito BP(2 * P);
				for (int j = 0; j < P; ++j) {
					BP.AgregarIzq(j);
					BP.AgregarDer(j + P);
					for (int k = 0; k < Heredity[j].size(); ++k) {
						int v = Heredity[j][k];
						if (Has[v])
							BP.AgregarArista(j, P + v);
					}
				}
				vector<Par> aux = BP.MaxEmparejamiento();
				if (aux.size() == lg)
					cout << "Y\n";
				else 
					cout << "N\n";
			}
		}
	}
	return 0;
}