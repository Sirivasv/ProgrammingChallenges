#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
typedef pair<int, int> pii;

vector<pii> grafo[MAXN];
bitset<MAXN> Fr;
int mxc;

//cost to get a node is cost[parent] + cost[parent][son];

pii DFS(int node, int cost) {
	pii resp = pii(0, 0);
	if (Fr[node]) {
		mxc = max(mxc, cost);
		resp.first = 1;
    }		
	int lim = grafo[node].size(); 
	for (int i = 0; i < lim; ++i) {
		int v = grafo[node][i].first;
		int c = grafo[node][i].second;
		pii temp = DFS(v, cost + c);
		if (temp.first) {
			resp.first = 1;
			resp.second += temp.second + c;
		}
	}
	return resp;
}

int main() {
	cin.tie(); ios_base::sync_with_stdio(0);
	int N, F, u, v, c, lim;
	cin >> N >> F;
	lim = N - 1;
	for (int i = 0; i < lim; ++i) {
		cin >> u >> v >> c;
		grafo[u].push_back(pii(v, c));
	}
	for (int i = 0; i < F; ++i) {
		cin >> u;
		Fr[u] = 1;
	}
	mxc = 0;
	pii ans = DFS(1, 0);
	cout << ans.second - mxc << '\n';
	return 0;
}