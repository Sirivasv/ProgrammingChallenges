#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 3000000;
const int MAXC = 30;

pii ari[MAXN];
int idar, parent[MAXC];

int Find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	parent[Find(u)] = Find(v);
}

bool MismoC(int u, int v) {
	return Find(u) == Find(v);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	string s;
	cin >> s;
	
	int lim = ((int)s.size()) / 2;
	int N = s.size();
	
	for (int i = 0; i < lim; ++i) {
		int u = s[i] - 'a';
		int v = s[((N - 1) - i)] - 'a';
		ari[idar].first = u;
		ari[idar].second = v;
		idar++;
		
	}
	
	for (int i = 0; i < MAXC; ++i)
		parent[i] = i;
	
	int ans = 0;
	
	for (int i = 0; i < idar; ++i) {
		int u = ari[i].first;
		int v = ari[i].second;
		if (MismoC(u, v))
			continue;
		ans++;
		Union(u, v);
	}
	
	cout << ans << '\n';
	
	return 0;
}