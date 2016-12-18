#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109;

int parent[MAXN], manyC;

int Find(int u) { return((parent[u] == u)?(u):(parent[u] = Find(parent[u]))); }

void Union(int u, int v) {
	if (Find(u) == Find(v))
		return;
	parent[Find(u)] = Find(v);
	manyC--;
}

typedef pair<int, int> pii;

pii arr[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i)
		parent[i] = i;
	int N;
	cin >> N;
	manyC = N;
	for (int i = 0; i < N; ++i) 
		cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if ((arr[i].first == arr[j].first) || (arr[i].second == arr[j].second))
				Union(i, j);
		}
	}
	cout << manyC - 1 << '\n';
	return 0;
}