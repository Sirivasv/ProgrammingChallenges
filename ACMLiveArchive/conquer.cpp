#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200009;

typedef long long lli;
typedef pair<lli, lli> pii;
typedef pair<lli, pii> ter;

ter Ari[MAXN];

int parent[MAXN];
lli sizec[MAXN], ans[MAXN];

int Find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v, lli p) {
	//cout << "unir: " << u << ' ' << v << '\n'; 
	ans[Find(v)] = max(ans[Find(u)] + (sizec[Find(v)] * p), ans[Find(v)] + (sizec[Find(u)] * p));
	//cout << ans[Find(v)] << '\n';
	sizec[Find(v)] += sizec[Find(u)];
	parent[Find(u)] = Find(v);
}

int idari = 0;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int N;
	while (cin >> N) {
		idari = 0;
		for (int i = 1; i < N; ++i) {
			int u, v;
			lli c;
			cin >> u >> v >> c;
			Ari[idari].first = -c;
			Ari[idari].second.first = u;
			Ari[idari++].second.second = v;
		}
		
		sort(Ari, Ari + idari);
		
		for (int i = 1; i <= N; ++i) {
			parent[i] = i;
			sizec[i] = 1;
			ans[i] = 0;
		}
		
		for (int i = 0; i < idari; ++i)
			Union(Ari[i].second.first, Ari[i].second.second, -Ari[i].first);
		
		cout << ans[Find(1)] << '\n';
	}
	return 0;
}