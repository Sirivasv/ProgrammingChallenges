#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;
typedef long long lli;

const int MAXN = 200004;
const int MAXQ = 200004;
const int MAXV = 1000004;

int arr[MAXN], many[MAXV], zone[MAXN], currL, currR;
ter queries[MAXQ];
pii queriesIF[MAXQ];
lli ans, ansQ[MAXQ];

inline lli getAns() { return ans; }

inline lli F(lli n, lli xi) { return ((xi * n) + (xi * (n + 1LL))); }

inline void remove(int idx) {
	many[arr[idx]]--;
	ans -= F(many[arr[idx]], arr[idx]);
}

inline void add(int idx) {
	ans += F(many[arr[idx]], arr[idx]);
	many[arr[idx]]++;
}

lli process(int nL, int nR) {
	
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
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	int limit = ceil(sqrt(N));
	for (int i = 0; i < N; ++i) zone[i] = i / limit;
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