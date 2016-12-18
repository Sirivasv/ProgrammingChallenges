#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;

int N, F, fr[MAXN], vis[MAXN], cst, mcst;
vector<pii> grafop[MAXN];

int DFS(int u, int cost = 0) {
	int flag = 0;
	if (fr[u]) {
		mcst = max(cost, mcst);
		flag = 1;
	}
	vis[u] = 1;
	for (int i = 0; i < grafop[u].size(); ++i) {
		int v = grafop[u][i].first;
		int p = grafop[u][i].second;
		if (vis[v])
			continue;
		if (DFS(v, cost + p)) {
			cst += p;
			flag = 1;
		}
	}
	return flag;
}

void Limpia(int n) {
	for (int i = 0; i < n; ++i) {
		grafop[i].clear();
		fr[i] = vis[i] = 0;
	}
	cst = mcst = 0;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N >> F) {
		Limpia(N);
		for (int i = 1; i < N; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			u--, v--;
			grafop[u].push_back(pii(v, c));
			grafop[v].push_back(pii(u, c));
		}
		for (int i = 0; i < F; ++i) {
			int u;
			cin >> u;
			u--;
			fr[u] = 1;
		}
		DFS(0);
		cout << cst - mcst << '\n';
	}
	return 0;
}