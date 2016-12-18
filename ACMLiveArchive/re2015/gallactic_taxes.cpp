#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, pdd> ter;
typedef pair<double, int> pdi;

const int MAXN = 1009;
const double INF = (1LL << 62);

double Dist[MAXN];
vector<ter> grafo[MAXN];

void Dijkstra(double x, int n) {
	for (int i = 0; i < n; ++i)
		Dist[i] = INF;
	priority_queue< pdi, vector<pdi>, greater<pdi> > Q;
	Q.push(pdi(0, 0));
	while (!Q.empty()) {
		int u = Q.top().second;
		double p = Q.top().first;
		Q.pop();
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i].first;
			double A = grafo[u][i].second.first;
			double B = grafo[u][i].second.second;
			double cost = A * x + B;
			if (Dist[v] > p + cost) {
				Dist[v] = p + cost;
				Q.push(pdi(p + cost, v));
			}
		}
	}
}

void Limpia(int n) {
	for (int i = 0; i < n; ++i)
		grafo[i].clear();
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	while (cin >> N >> M) {
		Limpia(N);
		for (int i = 0; i < M; ++i) {
			int u, v;
			double A, B;
			cin >> u >> v >> A >> B;
			u--, v--;
			grafo[u].push_back(ter(v, pdd(A, B)));
			grafo[v].push_back(ter(u, pdd(A, B)));
		}
		double ini = 0, fin = 24.0 * 60.0;
		for (int i = 0; i < 100; ++i) {
			double mid1 = (ini + fin) / 2.0;
			Dijkstra(mid1, N);
			double ans1 = Dist[N - 1];
			double mid2 = (mid1 + fin) / 2.0;
			Dijkstra(mid2, N);
			double ans2 = Dist[N - 1];
			if (ans1 > ans2) 
				 fin = mid2;
			else
				ini = mid1;
		}
		cout << fixed << setprecision(5) << Dist[N - 1] << '\n';
	}
	return 0;
}
