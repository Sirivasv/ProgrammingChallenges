#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

int memo[MAXN][MAXN];
int vis[MAXN][MAXN];
vector<int> grafo[MAXN];
int N, M, ID;

int DP(int u, int v) {
	if ((u == 0) || (v == 0))
		return 1;
	if (u == v)
		return 0;
	if (vis[u][v] == ID)
		return memo[u][v];
	vis[u][v] = ID;
	int minu = min(u, v), maxu = max(u, v);
	int fl = 0;
	for (int i = 0; i < grafo[maxu].size(); ++i) {
		int pmaxu = grafo[maxu][i];
		fl |= DP(minu, pmaxu);
	}
	return memo[u][v] = fl;
}

void Limpia() {
	for (int i = 0; i < N; ++i) {
		//for (int j = 0; j < N; ++j)
			//memo[i][j] = -1;
		grafo[i].clear();
	}
	ID++;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N >> M) {
		Limpia();
		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			grafo[max(a, b)].push_back(min(a, b));
		}
		int cnt = 0;
		for (int i = 0; i < N; ++i) 
			for (int j =  i + 1; j < N; ++j)
				if (DP(i, j)) {
					//cout << (i  + 1) << ' ' << (j + 1) << '\n';
					cnt++;
				}
		cout << cnt << '\n';
	}
	return 0;
}