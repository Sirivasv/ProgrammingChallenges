#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 100009;

vector<int> grafo[MAXN];

lli arr[MAXN];

pii DFS(int u, int p) {
	lli totsum = 0, totres = 0;
	
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v == p) continue;
		pii ans = DFS(v, u);
		totsum = max(totsum, ans.first);
		totres = max(totres, ans.second);
	}
	
	arr[u] += totsum;
	arr[u] -= totres;
	
	if (arr[u] > 0) totres += arr[u];
	if (arr[u] < 0) totsum -= arr[u];
	
	return pii(totsum, totres);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N;
	cin >> N;
	
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	
	for (int i = 0; i < N; ++i) cin >> arr[i];
	
	pii ans = DFS(0, -1);

	cout << (ans.first + ans.second) << '\n';
	
	return 0;
}