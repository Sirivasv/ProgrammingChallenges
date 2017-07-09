#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAXN = 100;
const int INF = 1 << 30;

vi grafo[MAXN];
int N, ri, rj, rr;

vector<int> BFS(int o, int nb) {
	vector<int> vis(N, 0);
	vector<int> dis(N, INF);
	vis[o] = 1; dis[o] = 0;
	queue<int> Q;
	Q.push(o);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i];
			if (dis[v] > (dis[u] + 1)) {
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
	}
	return dis;
}

int Try(int xi, int o, const vector<int>& vv) {
	vector<int> BFSO = BFS(o, xi);
	int mats = -1;
	for (int i = 0; i < N; ++i)
		if ((BFSO[i] != INF) && (vv[i] > mats))
			mats = vv[i];
	return mats;
}

int main() {
	cin >> N >> rr >> ri >> rj;
	rr--; ri--; rj--;
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	vector<int> BFSI = BFS(ri, -1);
	vector<int> BFSJ = BFS(rj, -1);
	cout << min(Try(ri, rr, BFSI), Try(rj, rr, BFSJ)) << '\n';
	return 0;
}