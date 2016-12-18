#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1009;
int memo[MAXN][MAXN][2], arista[MAXN][MAXN], n, m;

inline void PrintRDP(int izq, int der, int id) {
	int n_i = (izq - 1 + n) % n;
	int n_d = (der + 1) % n;
	int nodo = ((id)?der:izq);
	if ((n_i == n_d) && (arista[nodo][n_d])) {
		cout << n_i + 1 << '\n';
		return;
	}
	int ans = 0;
	if (arista[nodo][n_i]) ans |= memo[n_i][der][0];
	if (ans) {
		cout << n_i + 1 << '\n';
		PrintRDP(n_i, der, 0);
		return;
	}
	if (arista[nodo][n_d]) ans |= memo[izq][n_d][1];
	if (ans) {
		cout << n_d + 1<< '\n';
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
	
	for (int i = 0; i < n; ++i) 
		for (int id = 0; id < 2; ++id) {
			int izq = (i + 1) % n;
			int der = (i - 1 + n) % n;
			int nodo = ((id)?(der):(izq));
			memo[izq][der][id] = arista[nodo][i];
		}
		
    for (int size = 2; size < n; ++size) {
		for (int n_d = 0; n_d < n; ++n_d) {
			int n_i = (n_d + size - 1) % n;
			int izq = (n_i + 1) % n;
			int der = (n_d - 1 + n) % n;
			for (int id = 0; id < 2; ++id){
				int nodo = (id)?der:izq;
				int ans = 0;
				if (arista[nodo][n_i]) ans |= memo[n_i][der][0];
				if (arista[nodo][n_d]) ans |= memo[izq][n_d][1];
				memo[izq][der][id] = ans;
			}
		}
	}
	
	int nid = 0;
	for (; nid < n; ++nid) {
		if (memo[nid][nid][0]) break;
	}
	if (nid >= n) {
		cout << "-1\n";
		return 0;
	} 
	cout << nid + 1 << '\n';
	PrintRDP(nid, nid, 0);	
	return 0;
}