#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const long long INF = 1000000;

long long df1[MAXN], df2[MAXN], ma[MAXN], mb[MAXN];
int ml;
long long MD, dia, acum[MAXN];
vector<int> grafo[MAXN];

void Limpia(int n) {
	for (int i = 0; i < n; ++i)
		grafo[i].clear();
}

void BFS(int o, long long* dist, int n) {
	for (int i = 0; i < n; ++i)
		dist[i] = INF;
	dist[o] = 0;
	ml = o;
	queue<int> Q;
	Q.push(o);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i];
			if (dist[v] > (dist[u] + 1)) {
				dist[v] = dist[u] + 1;
				Q.push(v);
			}
		}
	}
	for (int i = 0; i < n; ++i)
		if (dist[i] > dist[ml])
			ml = i;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	while (cin >> N >> M) {
		Limpia(N);
		for (int i = 1; i < N; ++i) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		BFS(0, df1, N);
		BFS(ml, df1, N);
		BFS(ml, df2, N);
		dia = df2[ml]; 
		for (int i = 0; i < N; ++i)
			ma[i] = max(df1[i], df2[i]);
		Limpia(M);
		for (int i = 1; i < M; ++i) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		BFS(0, df1, M);
		BFS(ml, df1, M);
		BFS(ml, df2, M);
		MD = max(dia, df2[ml]);
		for (int i = 0; i < M; ++i)
			mb[i] = max(df1[i], df2[i]);
		sort(mb, mb + M);
		acum[M] = 0;
		for (int i = M - 1; i >= 0; --i)
			acum[i] = acum[i + 1] + mb[i];
		long long resacum = 0;
		for (int i = 0; i < N; ++i) {
			long long id = upper_bound(mb, mb + M, MD - ma[i] - 1) - mb;
			resacum += ((M - id) * ma[i]) + (M - id) + acum[id] + (id * MD);
		}
		double ans = ((double)resacum) / ((double)(((double)N)* ((double) M)));
		cout << fixed << setprecision(3) << ans << '\n';
	}
	return 0;
}