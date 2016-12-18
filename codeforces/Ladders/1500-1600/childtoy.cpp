#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 1009;

pii arr[MAXN];
lli barr[MAXN];
vector<int> grafo[MAXN];
bitset<MAXN> muerto;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> barr[i];
		arr[i].first = -barr[i];
		arr[i].second = i;
	}
	sort(arr, arr + N);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	lli sum = 0;
	for (int i = 0; i < N; ++i) {
		int u = arr[i].second;
		for (int j = 0; j < grafo[u].size(); ++j)
			if (!muerto[grafo[u][j]])
				sum += barr[grafo[u][j]];
		muerto[u] = 1;
	}
	cout << sum << '\n';
	return 0;
}