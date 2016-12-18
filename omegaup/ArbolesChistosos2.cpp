#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100009;
const int INF = 1000000009;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
piii aristas[MAXN];
int N, Q;
map<int, int> pesos;
int parent[MAXN], indpesos[MAXN];
long long acumval[MAXN], sz[MAXN];

void InitUF() {
	for (int i = 0; i <= N; ++i) {
		parent[i] = i;
		sz[i] = 1LL;
	}
	return;
}

int Find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = Find(parent[u]);
}

void Unir(int u, int v) {
	sz[Find(v)] += sz[Find(u)];
	parent[Find(u)] = Find(v);
	return;
}

long long Tamano(int u) {
	return sz[Find(u)];
}

void PreCalc(int mc) {
	int lim = N - 1;
	for (int i = 0; i < lim; ++i) {
		int u = aristas[i].second.first;
		int v = aristas[i].second.second;
		int c = pesos[aristas[i].first];
		long long total = Tamano(u) * Tamano(v);
		acumval[c] += total;
		Unir(u, v);
	}
	for (int i = 1; i <= mc; ++i)
		acumval[i] += acumval[i - 1];
	return;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> Q;
	
	int lim = N - 1;
	int cnt = 1;
	
	for (int i = 0; i < lim; ++i) {
		cin >> aristas[i].second.first >> aristas[i].second.second >> aristas[i].first;
		if (!pesos.count(aristas[i].first))
			pesos[aristas[i].first]++;
	}
	sort(aristas, aristas + lim);
	InitUF();
	
	indpesos[0] = 0;
	cnt = 1;
	for (map<int, int>::iterator it = pesos.begin(); it != pesos.end(); it++) {
		indpesos[cnt] = (*it).first;
		(*it).second = cnt++;
	}
	indpesos[cnt] = INF; 
	
	PreCalc(cnt);
	
	int l, r, lval, rval;
	for (int i = 0; i < Q; ++i) {
		cin >> l >> r;
		lval = lower_bound(indpesos, indpesos + cnt + 1, l) - indpesos;
		if (!lval) 
			cout << "0\n";
		else {
			rval = upper_bound(indpesos, indpesos + cnt + 1, r) - indpesos;
			rval--;
			cout << acumval[rval] - acumval[lval - 1] << '\n';
		}
	}
	return 0;
}