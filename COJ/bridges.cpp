#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 200009;

int parent[MAXN], sz[MAXN];

int Find(int u) { return ((parent[u] == u)? (u): (parent[u] = Find(parent[u]))); }

void Union(int u, int v) {
	if (Find(u) == Find(v))
		return;
	sz[Find(v)] += sz[Find(u)];
	parent[Find(u)] = Find(v);
}

pii Ari[MAXN];
int ans[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		map<string, int> mp;
		for (int i = 0; i < MAXN; ++i) {
			parent[i] = i;
			sz[i] = 1;
		}
		int nb = 1;
		for (int i = 0; i < N; ++i) {
			string s, ss;
			cin >> s >> ss;
			if (!mp.count(s))
				mp[s] = nb++;
			if (!mp.count(ss))
				mp[ss] = nb++;
			Union(mp[s], mp[ss]);
			cout << sz[Find(mp[s])] << '\n';
		}
	}
	return 0;
}