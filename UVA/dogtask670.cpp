#include <bits/stdc++.h>
using namespace std;

// Definiciones iniciales
typedef pair<int, int> Arista;
typedef pair<Arista, Arista> pp;

const int INF = 1 << 30;
const int MAXN = 250;

vector<int> grafo[MAXN];
int pareja[MAXN];
bool visitado[MAXN];
vector<int> l;
vector<int> r;

Arista rutag[MAXN];
Arista ipl[MAXN];
double dista[MAXN];
int N, M, T;

inline double Distan(Arista a, Arista b) {
	return (double)(sqrt((double)((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second))));
}	

inline int CaminoIncremental(int u) {
    visitado[u] = true;
    for (int i = 0; i < grafo[u].size(); ++i) {
        int v = grafo[u][i];
        if (pareja[v] == -1) 
            return pareja[v] = u;
        if (visitado[pareja[v]]) continue;
        if (CaminoIncremental(
            pareja[v]) != -1) return pareja[v] = u;
    }
    return -1;
}

inline vector<Arista> MaxEmparejamientoBipartito(
    const vector<int>& l, const vector<int>& r) {
    int n = l.size() + r.size();
    fill(pareja, pareja + n, -1);
    for (int i = 0; i < l.size(); ++i) {
        fill(visitado, visitado + n, false);
        CaminoIncremental(l[i]);
    }
    vector<Arista> parejas;
    for (int i = 0; i < r.size(); ++i)
        if (pareja[r[i]] != -1) parejas.push_back(
            Arista(pareja[r[i]], r[i]));
    return parejas;
}

inline void AddVertices(Arista x, int id) {
	for (int i = 0; i < N - 1; ++i) {    
		double d = Distan(rutag[i], x) + Distan(rutag[i + 1], x);
		if (dista[i] >= d) 
			grafo[i].push_back(id);
	}
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> T;
	int cnt = 0;
	while (T--) {
		if (cnt++) cout << '\n';
		cin >> N >> M;
		l.clear();
		r.clear();
		for (int i = 0; i < N; ++i) {
			cin >> rutag[i].first >> rutag[i].second;
			if (i) dista[i - 1] = 2.0 * Distan(rutag[i - 1], rutag[i]);
			l.push_back(i);
			grafo[i].clear();
		}
		for (int i = 0; i < M; ++i) {
			cin >> ipl[i].first >> ipl[i].second;
			AddVertices(ipl[i], i + N);
			r.push_back(i + N);
		}
		vector<Arista> MCBM = MaxEmparejamientoBipartito(l, r);
		int lim = MCBM.size() + N, lim_ = MCBM.size();
		cout << lim << '\n';
		int j = 0;
		sort(MCBM.begin(), MCBM.end());
		for(int i = 0; i < N; ++i) {
			if (i) cout << ' ';
			cout << rutag[i].first << ' ' << rutag[i].second;
			if (j < lim_) {
				if (MCBM[j].first <= i) {
					cout << ' ' << ipl[MCBM[j].second - N].first << ' ' << ipl[MCBM[j].second - N].second;
					++j;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}