#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 200009;

vector<pii> grafo[MAXN];
int upth[MAXN], dis[MAXN];

int Build(int u, int p, int upd, int gd) {
	upth[u] = upd;
	dis[u] = gd; 
	int ct = 0;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i].first;
		if (v != p) {
			int res = Build(v, u, upd + grafo[u][i].second, gd + 1);
			ct += res + grafo[u][i].second;
		}
	}
	return ct;
}

int main() {
	int N;
	scanf("%d\n", &N);
	for (int i = 1; i < N; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		grafo[u].push_back(pii(v, 0));
		grafo[v].push_back(pii(u, 1));
	}
	
	int UT = Build(1, 0, 0, 0);
	int mint = MAXN;
	
	for (int i = 1; i <= N; ++i)
 		mint = min(mint, UT - (2 * upth[i]) + dis[i]);
	
	printf("%d\n", mint);
	
	int cnt = 0;
	
	for (int i = 1; i <= N; ++i)
		if ((UT - (2 * upth[i]) + dis[i]) == mint) {
			if (cnt++) printf(" ");
			printf("%d", i);
		}
	
	printf("\n");
	
	return 0;
}