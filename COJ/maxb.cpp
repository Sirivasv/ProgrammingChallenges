#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Arista;
const int INF = 1 << 30;
const int MAXN = 20009;
vector<int> l, r;
int pareja[MAXN], N, M;
bool visitado[MAXN];
vector<int> grafo[MAXN];

int CaminoIncremental(int u) {
	visitado[u] = true;
	for (int i = 0; i < grafo[u].size(); ++i)
		if (pareja[grafo[u][i]] == -1)
			return pareja[grafo[u][i]] = u;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v =  grafo[u][i];
		if (visitado[pareja[v]]) continue;
		if (CaminoIncremental(pareja[v]) != -1)
			return pareja[v] = u;
	}
	return -1;
}

int MaxEmpB() {
	int n = l.size() + r.size();
	fill(pareja, pareja + n, -1);
	for (int i = 0; i < l.size(); ++i) {
		fill(visitado, visitado + n, false);
		CaminoIncremental(l[i]);
	}
	int cnt = 0;
	for (int i = 0; i < r.size(); ++i)
		if (pareja[r[i]] != -1) cnt++;
	return cnt;
}

void Limpia() {
	l.clear();
	r.clear();
	for (int i = 0; i < MAXN; ++i)
		grafo[i].clear();
	return;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N >> M) {
		if (!(N + M)) break;
		Limpia();
		for (int i = 0; i < N; ++i) {
			l.push_back(i);
			r.push_back(i + N);
		}
		int u, v;
		while(M--) {
			cin >> u >> v;
			grafo[u].push_back(v + N);
			grafo[v + N].push_back(u);
		}
		cout << MaxEmpB() << '\n';
	}	
	return 0;
}