#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;
int parent[MAXN], nconjuntos;

int N;

int Find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = Find(parent[u]);
} 

void Union(int u, int v) {
	if (Find(u) == Find(v))
		return;
	nconjuntos--;
	parent[Find(u)] = Find(v);
}

void Limpia() {
	int lim = (N << 1) * ((N << 1) + 1);
	for (int i = 0; i <= lim; ++i)
		parent[i] = i;
	nconjuntos = lim;
}

int GetN(int x, int y) {
	return (y * ((N << 1) + 1)) + x;
}

void Unir(char op, int i, int j) {
	int cx = j, cy = i;
	cx *= 2;
	if (i & 1)
		cx++;
	if (op == 'H') {
		Union(GetN(cx, cy), GetN(cx + 1, cy));
		Union(GetN(cx, cy + 1), GetN(cx + 1, cy + 1));
	} else {
		Union(GetN(cx, cy), GetN(cx, cy + 1));
		Union(GetN(cx + 1, cy), GetN(cx + 1, cy + 1));
	}
}

void UnirOrillas() {
	int lim = (N << 1) - 1;
	for (int i = 1; i <= lim; i += 2) {
		Union(GetN(i, 0), GetN(i + 1, 0));
		Union(GetN(i, lim), GetN(i + 1, lim));
	}
	for (int i = 1; i <= lim - 2; i += 2)
		Union(GetN(0, i), GetN(0, i + 1));
	for (int i = 0; i <= lim - 1; i += 2)
		Union(GetN(lim + 1, i), GetN(lim + 1, i + 1));
	
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N) {
		char c;
		Limpia();
		for (int i = 0; i < ((N << 1) - 1); ++i)
			for (int j = 0; j < N; ++j) {
				cin >> c;
				Unir(c, i, j);
			}
		UnirOrillas();
		cout << nconjuntos - 1 << '\n'; 
	}
	return 0;
}