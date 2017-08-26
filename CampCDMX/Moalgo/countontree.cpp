#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;

const int MAXN = 100004;
const int SIZE = 200004;
const int DEPTH = 3;
const int MAXP = 19;

vector<int> grafo[MAXN];
int eupath[SIZE], EL, arr[MAXN], ans, hasLCA[MAXN], zone[MAXN], currR, currL, querieans[MAXN], h[MAXN], p[MAXN][MAXP], manyn[MAXN];
pii treeIF[MAXN], querierange[MAXN], arrb[MAXN];
ter queries[MAXN];
int many[MAXN];
//map<int, int> many;
//unordered_map<int, int> many;

void DFS(int u, int parent = -1) {
	treeIF[u].first = EL;
	eupath[EL++] = u;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (v == parent) continue;
		h[v] = h[u] + 1; p[v][0] = u;
		for (int j = 1; j < MAXP; ++j) p[v][j] = p[p[v][j - 1]][j - 1];
		DFS(v, u);
	}
	treeIF[u].second = EL;
	eupath[EL++] = u;
}

inline int parent(int u, int pid) {
	for (int i = 0; i < MAXP; ++i) if (pid & (1 << i)) u = p[u][i]; 
	return u;
}

inline int LCA(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	u = parent(u, h[u] - h[v]);
	for (int i = MAXP - 1; i >= 0; --i) if (p[u][i] != p[v][i]) {
		u = p[u][i];
		v = p[v][i];
	}
	return ((u == v)?(u):(p[u][0]));
}

inline bool Contiene(int u, int v) { return ((treeIF[u].second >= treeIF[v].second) && (treeIF[u].first <= treeIF[v].first)); }
inline int getAns() { return ans; }

inline void remove(int idx) {
	int val = arr[eupath[idx]];
	manyn[eupath[idx]]--;
	if (manyn[eupath[idx]] == 1) {
		many[val]++;
		if (many[val] == 1) ans++;	
	} else {
		many[val]--;
		if (!many[val]) ans--;
	}
}

inline void add(int idx) {
	int val = arr[eupath[idx]];
	manyn[eupath[idx]]++;
	if (manyn[eupath[idx]] == 2) {
		many[val]--;
		if (!many[val]) ans--;	
	} else {
		many[val]++;
		if (many[val] == 1) ans++;
	}
}

inline int process(int ix, int nL, int nR) {
	//cout << currL << ' ' << currR << ' ' << nL << ' ' << nR << '\n';  
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
	int res;
	if (hasLCA[ix] != -1) {
		add(hasLCA[ix]);
		res = getAns();
		remove(hasLCA[ix]);
	} else res = getAns();
	//cout << res << '\n';
	return res;
}

pii Query(int ix, int u, int v) {
	if (Contiene(u, v)) return pii(treeIF[u].first, treeIF[v].first); //process(treeIF[u].first, treeIF[v].first); //cout << "t1 - I: " << treeIF[u].first << " F: " << treeIF[v].first << '\n';
	else if (Contiene(v, u)) return pii(treeIF[v].first, treeIF[u].first); //process(treeIF[v].first, treeIF[u].first); //cout << "t2 - I: " << treeIF[v].first << " F: " << treeIF[u].first << '\n';
	hasLCA[ix] = treeIF[LCA(u, v)].first;
	//cout << treeIF[u].first << ' ' << treeIF[u].second << '\n'; 
	//cout << treeIF[v].first << ' ' << treeIF[v].second << '\n'; 
	//cout << ix << ' ' << LCA(u, v) << ' ' << treeIF[LCA(u, v)].first << '\n';
	return pii(min(treeIF[u].second, treeIF[v].second), max(treeIF[u].first, treeIF[v].first));//process(min(treeIF[u].second, treeIF[v].second), max(treeIF[u].first, treeIF[v].first));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	//scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) { cin >> arrb[i].first; arrb[i].second = i; }
	sort(arrb + 1, arrb + N + 1);
	arr[arrb[1].second] = 1;
	for (int i = 2; i <= N; ++i) 
		if (arrb[i].first == arrb[i - 1].first) arr[arrb[i].second] = arr[arrb[i - 1].second];
		else arr[arrb[i].second] = arr[arrb[i - 1].second] + 1; 
	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		//scanf("%d%d", &u, &v);
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	DFS(1);
	int limit = ceil(sqrt(EL));
	for (int i = 0; i < EL; ++i) zone[i] = i / limit;
	//for (int i = 0; i < eupath.size(); ++i) { cout << eupath[i] << ' '; } cout << '\n';
	//for (int i = 1; i <= N; ++i) cout << treeIF[i].first << ' ' << treeIF[i].second << '\n';
	add(0);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		//scanf("%d%d", &u, &v);
		//cout << "*****************\n";
		//cout << "Qu: " << treeIF[u].first << " - " << treeIF[u].second << '\n';
		//cout << "Qv: " << treeIF[v].first << " - " << treeIF[v].second << '\n';
		hasLCA[i] = -1;
		pii qr = Query(i, u, v);
		queries[i].first.first = zone[qr.first];
		queries[i].first.second = zone[qr.second];
		queries[i].second = i;
		querierange[i] = qr;
	}
	sort(queries, queries + M);
	for (int i = 0; i < M; ++i) {int id = queries[i].second; querieans[id] = process(id, querierange[id].first, querierange[id].second); }
	for (int i = 0; i < M; ++i) cout << querieans[i] << '\n'; //printf("%d\n", querieans[i]); //	
	return 0;
}