#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<char, pii> pci;

const int MAXN = 1009;

int par[MAXN];

int Find(int u) {
	if (par[u] == u) return u;
	return par[u] = Find(par[u]);
}

int Union(int u, int v) {
	par[Find(u)] = Find(v);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, K;
	cin >> N >> M >> K; 
	vector<pci> Ar;
	for (int i = 0; i < N; ++i)
		par[i] = i;
	for (int i = 0; i < M; ++i) {
		char O;
		int u, v;
		cin >> O >> u >> v;
		u--, v--;
		Ar.push_back(pci(O, pii(u, v)));
	}
	// RED KRUSKAL
	int manyr = 0;
	for (int i = 0; i < M; ++i) {
		char c = Ar[i].first;
		int u = Ar[i].second.first;
		int v = Ar[i].second.second;
		if (c == 'B')
			continue;
		if (Find(u) == Find(v))
			continue;
		Union(u, v);
		manyr++;
	}
	for (int i = 0; i < N; ++i)
		par[i] = i;
	//BLUE KRUSKAL
	int manyb = 0;
	for (int i = 0; i < M; ++i) {
		char c = Ar[i].first;
		int u = Ar[i].second.first;
		int v = Ar[i].second.second;
		if (c == 'R')
			continue;
		if (Find(u) == Find(v))
			continue;
		Union(u, v);
		manyb++;
	}
	if ((manyr >= (N - K - 1)) && (manyb >= K))
		cout << "1\n";
	else
		cout << "0\n";
	return 0;
}