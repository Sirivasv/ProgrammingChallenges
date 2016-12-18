#include <bits/stdc++.h>
using namespace std;

#define cost first
#define U second.first
#define V second.second

typedef pair<int, int> pii;
typedef pair<int, pii> Ar;

const int MAXN = 300000;

Ar edge[MAXN];
int parent[MAXN];

int Find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	parent[Find(u)] = Find(v);
}

bool MC(int u, int v) {
	return Find(u) == Find(v);
}

void initUF(int n) {
	for (int i = 0; i < n; ++i)
		parent[i] = i;
}

bool Can(int n) {
	for (int i = 1; i < n; ++i)
		if (Find(i) != Find(0))
			return false;
	return true;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, L;
	cin >> N >> M >> L;
	initUF(N);
	int sum = 0;
	for (int i = 0; i < M; ++i) {
		cin >> edge[i].U >> edge[i].V >> edge[i].cost;
		if (i < L)
			sum += edge[i].cost;
	}
	sort(edge, edge + M);
	int minc = 0;
	for (int i = 0; i < M; ++i) {
		int u = edge[i].U - 1;
		int v = edge[i].V - 1;
		if (MC(u, v))
			continue;
		minc += edge[i].cost;
		Union(u, v);
	}
	if ((minc <= sum) && Can(N))
		cout << "possible\n";
	else
		cout << "impossible\n";
	return 0;
}