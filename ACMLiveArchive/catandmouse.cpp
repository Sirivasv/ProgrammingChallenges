#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
// Definiciones iniciales
typedef pair<long long, long long> Arista;
const int MAXN = 450;
const double EPS = 1e-8;

vector<int> grafo[MAXN];
int pareja[MAXN];
bool visitado[MAXN];
vector<int> l;
vector<int> r;

Arista cat[MAXN], mouse[MAXN];
int N, K;

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


inline void BuildGraph(double distan) {
	for (int i = 0; i < N; ++i) {
		grafo[i].clear();
		for (int j = 0; j < N; ++j) 
			if (Distan(cat[i], mouse[j]) > distan) grafo[i].push_back(j + N);
	}
	return ;
}

inline int MIS(double mindist) {
	BuildGraph(mindist);
	vector<Arista> MCBM = MaxEmparejamientoBipartito(l, r);
	//cout << mindist << '\n';
	//cout <<  MCBM.size() << '\n';
	return ((N << 1) - MCBM.size());
}

inline double BusBin() {
	double ini = 0.0, mid, fin = 1000000000, ans = 0.0;
	while (fin - ini >= EPS) {
		//cout << fin << " // " << ini << '\n';
		mid = (fin + ini) / 2.0;
		if (MIS(mid) >= K) {
			ans = mid;
			fin = mid;
		} else ini = mid;
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> N >> K) {
		l.clear();
		r.clear();
		for (int i = 0; i < N; ++i) {
			cin >> cat[i].first >> cat[i].second;
			l.push_back(i);
		}
		for (int i = 0; i < N; ++i){
			cin >> mouse[i].first >> mouse[i].second;
			r.push_back(i + N);
		}
		cout << fixed;
		cout << setprecision(11) << BusBin() << '\n';
	}
	return 0;
}