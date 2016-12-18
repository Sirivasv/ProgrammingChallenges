#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

int parent[MAXN];
int cnt[MAXN];
vector<int> grafo[MAXN];

inline int Find(int u) { return ((parent[u] == u) ? (u) : (parent[u] = Find(parent[u]))); }

int main() {
	cin.tie(0);	ios_base::sync_with_stdio(0);
	int N, M;
	while (cin >> N >> M) {
		int res = 0;
		for (int i = 0; i <= N; ++i) {
			grafo[i].clear();
			parent[i] = -1;
			cnt[i] = 0;
		}
		for (int i = 0; i < M; ++i) {
			int u, v;
			cin >> u >> v;
			if (u == 1)
				parent[v] = v;
			else 
				grafo[v].push_back(u);
		}
		for (int i = 2; i <= N; ++i) {
			if (parent[i] == i)
				continue;
			for (int j = 0; j < grafo[i].size(); ++j) {
				if (parent[i] == -1)
					parent[i] = grafo[i][j];
				else if (Find(i) != Find(grafo[i][j]))
					parent[i] = i;
			}
		}
		for (int i = 2; i <= N; ++i)
			cnt[Find(i)]++;
		for (int i = 2; i <= N; ++i)
			res += cnt[i] * (N - 1 - cnt[i]);
		cout << (res / 2 + N - 1) << '\n';
	}
	return 0;
}