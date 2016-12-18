#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
int g[MAXN];

inline int find(int x) {
	if (g[x] == x) return x;
	return g[x] = find(g[x]);
}

inline void Unir(int u, int v) {
	g[find(u)] = find(v);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i) g[i] = i;
	int T, ini = 0, n, a, b;
	cin >> T;
	while (T--) {
		cin >> n;
		int sts = n;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			a--;
			a += ini;
			b = i + ini;
			if (find(a) != find(b)) {
				Unir(a, b);
				sts--;
			}
		}
		cout << sts << '\n';
		ini += n;
	}
	return 0;
}