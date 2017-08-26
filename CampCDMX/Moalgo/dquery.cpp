#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;

const int MAXN = 30009;
const int MAXQ = 200009;
const int MAXV = 1000009;

int arr[MAXN], many[MAXV], ans, zone[MAXN], currL, currR, ansQ[MAXQ];
ter queries[MAXQ];
pii queriesIF[MAXQ];

inline int getAns() { return ans; }

inline void remove(int idx) {
	many[arr[idx]]--;
	if (!many[arr[idx]]) ans--;
}

inline void add(int idx) {
	many[arr[idx]]++;
	if (many[arr[idx]] == 1) ans++;
}

int process(int nL, int nR) {
	
	while (currL > nL) {
		currL--;
		add(currL);
	}
	while (currL < nL) {
		remove(currL);
		currL++;
	}
	while (currR > nR) {
		remove(currR);
		currR--;
	}
	while (currR < nR) {
		currR++;
		add(currR);
	}

	return getAns();
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	int limit = ceil(sqrt(N));
	for (int i = 0; i < N; ++i) zone[i] = i / limit;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int ini, fin;
		cin >> ini >> fin;
		ini--; fin--;
		queries[i].first.first = zone[ini];
		queries[i].first.second = zone[fin];
		queries[i].second = i;
		queriesIF[i].first = ini;
		queriesIF[i].second = fin;
	}
	add(0); //First element
	sort(queries, queries + Q);
	for (int i = 0; i < Q; ++i) { int id = queries[i].second; ansQ[id] = process(queriesIF[id].first, queriesIF[id].second); }
	for (int i = 0; i < Q; ++i) cout << ansQ[i] << '\n';
	return 0;
}