#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1009;
int memo[MAXN][MAXN][2], arista[MAXN][MAXN], n, m;

inline int F(int izq, int der, int id) {
	if (memo[izq][der][id] != -1) return memo[izq][der][id];
	int n_i = (izq - 1 + n) % n;
	int n_d = (der + 1) % n;
	int nodo = ((id)?(der):(izq));
	//printf("nodo: %d\n", nodo);
	//printf("nodoizq: %d\n", n_i);
	//printf("nododer: %d\n", n_d);
	if ((n_i == n_d) && (arista[nodo][n_d])) return memo[izq][der][id] = 1;
	if ((n_i == n_d) && (!arista[nodo][n_d])) return memo[izq][der][id] = 0;
	int ans = 0;
	if (arista[nodo][n_i]) ans |= F(n_i, der, 0);
	if (arista[nodo][n_d]) ans |= F(izq, n_d, 1);
	return memo[izq][der][id] = ans;
}

inline void PrintRDP(int izq, int der, int id) {
	int n_i = (izq - 1 + n) % n;
	int n_d = (der + 1) % n;
	int nodo = ((id)?der:izq);
	if ((n_i == n_d) && (arista[nodo][n_d])) {
		printf("%d\n", n_i + 1);
		return;
	}
	int ans = 0;
	if (arista[nodo][n_i]) ans |= F(n_i, der, 0);
	if (ans) {
		printf("%d\n", n_i + 1);
		PrintRDP(n_i, der, 0);
		return;
	}
	if (arista[nodo][n_d]) ans |= F(izq, n_d, 1);
	if (ans) {
		printf("%d\n", n_d + 1);
		PrintRDP(izq, n_d, 1);
		return;
	}
	return;
} 

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < 2; ++k) memo[i][j][k] = -1;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		a--; b--;
		arista[a][b] = arista[b][a] = 1;
	}
	int nid = 0;
	for (; nid < n; ++nid) {
		if (F(nid, nid, 0)) break;
	}
	if (nid >= n) {
		printf("-1\n");
		return 0;
	} 
	printf("%d\n", nid + 1);
	PrintRDP(nid, nid, 0);	
	return 0;
}