#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;

struct Grafo {

    int n; bool bi;
    vector<vector<int>> ady;
    Grafo(int N, bool B = true)
        : n(N), bi(B), ady(N) {}

    void AgregarArista(int u, int v) {
        if (bi) ady[v].push_back(u);
        ady[u].push_back(v);
    }
	
	vector<int> ciclo;
    vector<char> color;

    void DetectarCiclo(int u, int p) {
        int retorno = bi? 0: 1;
        color[u] = ciclo.empty()? 'G': 'N';
        for (int v : ady[u]) {
            if (v == p && !retorno++) continue;
            if (ciclo.empty() && color[v] == 'G') {
                color[v] = 'A', ciclo.push_back(v);
                if (u != v) color[u] = 'R',
                    ciclo.push_back(u);
            }
            if (color[v] != 'B') continue;

            DetectarCiclo(v, u);
            if (color[u] == 'G' && color[v] == 'R')
                color[u] = 'R', ciclo.push_back(u);
        }
        if (color[u] == 'G') color[u] = 'N';
    }

    vector<vector<int>> DetectarCiclos() {
        vector<vector<int>> ciclos;
        color = vector<char>(n, 'B');
        for (int u = 0; u < n; ++u) {
            if (color[u] != 'B') continue;
            ciclo.clear(); DetectarCiclo(u, n);
            reverse(ciclo.begin(), ciclo.end());
            if (!ciclo.empty())
                ciclos.push_back(ciclo);
        }
        return ciclos;
    }

};

int N;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	Grafo grafodi(N, false);
	for (int i = 0; i < N; ++i) {
		int v;
		cin >> v;
		v--;
		//cout << i << ' ' << v << '\n';
		grafodi.AgregarArista(i, v);
	}
	vector< vector<int> > dciclos = grafodi.DetectarCiclos();
	int sum = 0, lim = dciclos.size();
	for (int i = 0; i < lim; ++i)
		sum += dciclos[i].size();
	if (sum != N)
		cout << "-1\n";
	else {
		lli ans = 1LL;
		for (int i = 0; i < lim; ++i) {
			//cout << dciclos[i].size() << '\n';
			lli val = ((dciclos[i].size() & 1)?(dciclos[i].size()):(dciclos[i].size() / 2));
			ans = (ans * val) / __gcd(ans, val);
		}
		cout << ans << '\n';
	}
	return 0;
}