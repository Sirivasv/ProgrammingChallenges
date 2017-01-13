#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;
const int MAXK = 9;

vector<int> grafo[MAXN];
int vis[MAXN], bestp[MAXN];

void DFS(int u, int& ans) {
	vis[u] = 1;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (!vis[v])
			DFS(v, ans);
		bestp[u] = max(bestp[u], bestp[v] + 1);
	}
	bestp[u] = max(bestp[u], 1);
	ans = max(ans, bestp[u]);
}

int longestPath(int N) {
	int ans = 0;
	for (int i = 1; i <= N; ++i) 
		if (!vis[i])
			DFS(i, ans);
	return ans;
}

int pos[MAXK][MAXN];
int arr[MAXK][MAXN];

int main() {
	
	int N, K;
	
	scanf("%d%d", &N, &K);
	
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &arr[i][j]);
			pos[i][arr[i][j]] = j;
 		}
	}
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			if (i == j) continue;
			int ok = 1;
			for (int k = 0; k < K; ++k)
				if (pos[k][i] > pos[k][j]) ok = 0;
			if (ok) grafo[i].push_back(j);
		}
	
	printf("%d\n", longestPath(N));	
	return 0;
}