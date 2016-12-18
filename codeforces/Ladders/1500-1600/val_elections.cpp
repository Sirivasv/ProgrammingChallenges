#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int mw[MAXN];
vector<int> grafo[MAXN];

int DFS(int u, int pu) {
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v == pu) continue;			
		mw[u] += DFS(v, u); 
	}
	return mw[u];
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 1; i < N; ++i) {
		int u, v, t;
		cin >> u >> v >> t;
		u--; v--;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
		if (t == 2) {
			mw[u] = 1;
			mw[v] = 1;
		}
	}
	DFS(0, -1);
	vector<int> ans;
	for (int i = 0; i< N; ++i)
		if (mw[i] == 1)
			ans.push_back(i + 1);
	cout << ans.size() << '\n';
	for (auto it : ans) {
		if (it != ans[0])
			cout << ' ';
		cout << it;
	}
	if (ans.size())
		cout << '\n';
	return 0;
}