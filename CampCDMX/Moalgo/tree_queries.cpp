#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<int, int> pii;
typedef pair<pii, int> ter;

const int MAXN = 100009;
const int MAXQ = 100009;

int arr[MAXN], ansQ[MAXQ], treearr[MAXN], kquerie[MAXQ], zone[MAXN], currL, currR, many[MAXN], N, M, BIT[MAXN], nodequerie[MAXN];
pii treeIF[MAXQ];
ter queries[MAXQ];
vector<int> grafo[MAXN];

inline int DFS(int u, int t = 1, int p = -1) {
	treeIF[u].first = t;
	treearr[t] = arr[u];
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v == p) continue;
		t = DFS(v, t + 1, u);
	}
	treeIF[u].second = t;
	return t;
}

inline void Upd(int idx, int val) {
	if (idx <= 0) return;
	while (idx < MAXN) {
		BIT[idx] += val;
		idx += (idx & (-idx));
	}
}

inline int Qr(int idx) {
	int res = 0;
	while (idx) {
		res += BIT[idx];
		idx -= (idx & (-idx));
	}
	return res;
}

inline void add(int idx) {
	Upd(many[treearr[idx]], -1);
	many[treearr[idx]]++;
	Upd(many[treearr[idx]], 1);
}

inline void remove(int idx) {
	Upd(many[treearr[idx]], -1);
	many[treearr[idx]]--;
	Upd(many[treearr[idx]], 1);
}

inline int getAns(int k) { return Qr(N) - Qr(k - 1); }

inline int process(int nL, int nR, int k) {
	//printf("%d %d - %d %d\n", currL, currR, nL, nR);
	while (currL < nL) {
		remove(currL);
		currL++;
	}
	while (currL > nL) {
		currL--;
		add(currL);
	}
	while (currR < nR) {
		currR++;
		add(currR);
	}
	while (currR > nR) {
		remove(currR);
		currR--;
	}
	return getAns(k);
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	//cin >> N >> M;
	scanf("%d%d", &N, &M);

	int limit = ceil(sqrt(N));
	for (int i = 1; i <= N; ++i) zone[i] = (i - 1) / limit;

	for (int i = 1; i <= N; ++i) cin >> arr[i];
	for (int i = 1; i < N; ++i) {
		int u, v;
		//cin >> u >> v;
		scanf("%d%d", &u, &v);
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	DFS(1);
	//for (int i = 1; i <= N; ++i) cout << i << ' ' << zone[i] << '\n';
	//for (int i = 1; i <= N; ++i) cout << treeIF[i].first << ' ' << treeIF[i].second << '\n';
	//for (int i = 1; i <= N; ++i) cout << i << ' ' << treeIF[i].first << ' ' << treeIF[i].second << ' ' << treearr[treeIF[i].first] << '\n';
	for (int i = 0; i < M; ++i)  {
		int n, k;
		//cin >> n >> k;
		scanf("%d%d", &n, &k);
		kquerie[i] = k;
		nodequerie[i] = n;
		queries[i].first.first = zone[treeIF[n].first];
		queries[i].first.second = zone[treeIF[n].second];
		queries[i].second = i;
	}
	sort(queries, queries + M);
	add(1); currL = currR = 1; //add first element
	for (int i = 0; i < M; ++i) { 
		int id = queries[i].second; 
		//printf("va a pasar id: %d node: %d ini: %d fin: %d k: %d\n", id, nodequerie[id], treeIF[nodequerie[id]].first, treeIF[nodequerie[id]].second, kquerie[id]);
		ansQ[id] = process(treeIF[nodequerie[id]].first, treeIF[nodequerie[id]].second, kquerie[id]); 
		//printf("paso %d\n", id);
	} 
	for (int i = 0; i < M; ++i) printf("%d\n", ansQ[i]); //cout << ansQ[i] << '\n'; //
	return 0;
}