#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 100;

vector<int> grafo[MAXN];
lli vals[MAXN];
set<int> ans;

bool isCubic(double xi) {
	double rt = cbrt(xi);
	rt = rt * rt * rt;
	return (rt == xi);
}

void DFS(int u, int dest, lli val, int dist = 1, int p = -1) {
	if (u == dest){
		if (isCubic(val)) ans.insert(-dist);
		return;
	}
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v == p) continue;
		DFS(v, dest, val * vals[v], dist + 1, u);
	}
	return;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> vals[i];
			grafo[i].clear();
		}
		for (int i = 2; i <= N; ++i) {
			int u, v;
			cin >> u >> v;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}
		ans.clear();
		for (int i = 1; i <= N; ++i)
			for (int j = i; j <= N; ++j)
				DFS(i, j, vals[i]);
		if (ans.size())
			cout << (-(*ans.begin())) << '\n';
		else 
			cout << "-1\n";
	}
	return 0;
}