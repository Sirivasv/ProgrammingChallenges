#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int parent[MAXN];

int Find(int u) { return ((parent[u] == u)?(u):(parent[u] = Find(parent[u]))); } 

void Union(int u, int v) {
	if (Find(u) == Find(v)) return;
	parent[Find(u)] = Find(v);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M; 
	
	for (int i = 0; i < M; ++i)
		parent[i] = i;
	
	set<int> spoken, regions;
	
	int empty = 0;
	
	for (int i = 0; i < N; ++i) {
		int prev, cur, ml;
		cin >> ml;
		if (!ml) empty++;
		for (int j = 0; j < ml; ++j) {
			cin >> cur;
			cur--;
			spoken.insert(cur);
			if (!j) prev = cur;
			Union(cur, prev);
			prev = cur;
		}
	}
	
	for (const auto& it : spoken)
		regions.insert(Find(it));
	
	cout << (max(((int)regions.size()) - 1, 0) + empty) << '\n';
	return 0;
}