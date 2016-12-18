#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;

int vis[MAXN], mats;
vector<int> grafo[MAXN], raices;

void BFS(int o) {
	vis[o] = 1;
	queue<int> Q;
	Q.push(o);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		mats = max(vis[u], mats);
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i];
			if (vis[v])
				continue;
			vis[v] = vis[u] + 1;
			Q.push(v);
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int v;
		cin >> v;
		if (v == -1) {
			raices.push_back(i);
			continue;
		}
		v--;
		grafo[v].push_back(i);
	}
	for (int i = 0; i < raices.size(); ++i)
		BFS(raices[i]);
	cout << mats << '\n';
	return 0;
}