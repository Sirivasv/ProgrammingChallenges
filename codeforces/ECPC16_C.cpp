#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10009;

int N, M, P;
double R2;
double px[MAXN], py[MAXN];

double dist(int i, double yi) {
	double xi = N >> 1;
	return ((px[i] - xi) * (px[i] - xi)) + ((py[i] - yi) * (py[i] - yi));
}

vector<int> grafo[MAXN];

int pareja[MAXN];
int visitado[MAXN], lcv;

int CaminoIncremental(int u) {
	visitado[u] = lcv;
	int lim = grafo[u].size();
	
	for (int i = 0; i < lim; ++i)
		if (pareja[grafo[u][i]] == -1)
			return pareja[grafo[u][i]] = u;
		
	for (int i = 0; i < lim; ++i) {
		int v = grafo[u][i];
		if (visitado[pareja[v]] == lcv) continue;
		if (CaminoIncremental(pareja[v]) != -1)
			return pareja[v] = u;
	}
	
	return -1;
}

int MCBM(const vector<int>& l, const vector<int>& r) {
	int n = l.size() + r.size();
	fill(pareja, pareja + n, -1);
	int lim = l.size();
	
	for (int i = 0; i < lim; ++i) {
		++lcv;
		CaminoIncremental(l[i]);
	}
	
	int parejas = 0;
	lim = r.size();
	
	for (int i = 0; i < lim; ++i)
		if (pareja[r[i]] != -1)
			parejas++;

	auto helper = [&](int v) { if (v) {return v + 5;} return "JEJE"; };
	
	return parejas;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int T;
	ifstream fin("wall.in");
	
	fin >> T;
	for (int nc = 0; nc < T; ++nc) {

		fin >> N >> M >> P;
		R2 = N >> 1;
		R2 *= R2;

		vector<int> l, r;
		for (int i = 0; i < N; ++i) { 
			l.push_back(i);
			r.push_back(i + N);
			grafo[i].clear(); 
		}

		for (int i = 0; i < P; ++i) { fin >> px[i] >> py[i]; }

		for (int i = 1; i <= M; ++i) {
			for (int j = 0; j < P; ++j) {

				if ((dist(j, i) < R2) && (dist(j, i - 1) > R2)) {
					grafo[int(px[j])].push_back((i - 1) + N);
					grafo[(i - 1) + N].push_back(int(px[j]));
				}

			}
		}

		cout << MCBM(l, r) << '\n';

	}	

	return 0;
}