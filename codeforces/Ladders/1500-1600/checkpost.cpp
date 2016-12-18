#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100009;
const int INF = 1 << 30;
const lli MOD = 1000000007LL;

int N;
lli juC[MAXN];

vector<int> grafo[MAXN];
int numeracion, top_activo;
int low[MAXN], num[MAXN], activo[MAXN];
vector< vector<int> > CFCs;

void ObtenerCFCs_(int u) {
	activo[top_activo++] = u;
	low[u] = num[u] = ++numeracion;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (!num[v]) ObtenerCFCs_(v);
		low[u] = min(low[u], low[v]);
	}
	if (low[u] == num[u]) {
		vector<int> CFC;
		while (activo[top_activo - 1] != u) {
			CFC.push_back(activo[--top_activo]);
			low[activo[top_activo]] = INF;
		} 
		CFC.push_back(activo[--top_activo]);
		low[u] = INF; CFCs.push_back(CFC);
	}
}

void ObtenerCFCs(int n) {
	CFCs.clear();
	numeracion = 0;
	fill(num, num + n, 0);
	fill(low, low + n, 0);
	for (int i = 0; i < n; ++i)
		if (!num[i]) ObtenerCFCs_(i);
} 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> juC[i];
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		grafo[u].push_back(v);
	}
	ObtenerCFCs(N);
	lli mint = 0;
	lli manyt = 1LL;
	for (int i = 0; i < CFCs.size(); ++i) {
		lli pmint = 10000000000LL;
		lli cnt = 0;
		for (int j = 0; j < CFCs[i].size(); ++j) {
			if (juC[CFCs[i][j]] < pmint) {
				pmint = juC[CFCs[i][j]];
				cnt = 0;
			}
			if (juC[CFCs[i][j]] == pmint)
				cnt++;
		}
		mint += pmint;
		manyt = (manyt * cnt) % MOD;
	}
	cout << mint << ' ' << manyt << '\n';
	return 0;
}