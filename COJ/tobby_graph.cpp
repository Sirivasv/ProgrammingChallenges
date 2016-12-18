#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10009;
int parent[MAXN], sz;
int N, M;

int Find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Unir(int u, int v) {
	parent[Find(u)] = Find(v);
	return;
}

bool MismoConjunto(int u, int v) {
	return Find(u) == Find(v);
}

void Limpia() {
	for (int i = 0; i < N; ++i) {
		grafo[i].clear();
		parent[i] = i;
	}
	sz = N;
	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		Limpia();
		int a, b;
		for (int i = 0; i < M; ++i) {
			cin >> a >> b;
			a--, b--;
			if (!MismoConjunto(a, b)) {
				sz--;
				Unir(a, b);
			}
		}
		cout << (sz * (sz -1) >> 1) << '\n';
	}
	return 0;
}