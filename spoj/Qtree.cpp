#include<bits/stdc++.h>
using namespace std;
//chainNo - current Chain while making HLD
//chainInd[x] - Given x node, to which chain does x belong to.
//posInBase[x] - Given x node - what is the position of x in baseArray.
//chainHead[y] - Given y chain, what is the head of the chain
//subsize[y] - Given a chain, what is the length of the chain
const int MAXN = 10100;
const int LN = 14;
typedef pair<int, int> pii;
vector< pii > grafo[MAXN]; //first v, second cost of the edge
vector<int> indexx[MAXN]; //thing to know index of the edge
int otherEnd[MAXN]; //same for the index m9
int baseArray[MAXN], ptr; //BaseArray and the size of ST to buil it
int chainNo, chainInd[MAXN], chainHead[MAXN], posInBase[MAXN], subsize[MAXN]; //explained above
int level[MAXN], P[LN][MAXN], loga[LN]; //LCA stuff m8
int ST[MAXN << 2]; //SegTree structure

/* Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */
 void HLD(int curNode, int cost, int prev) {
	 if (chainHead[chainNo] == -1) 
		chainHead[chainNo] = curNode;
	ptr++;
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr] = cost;
	
	int sc = -1, ncost, lim = grafo[curNode].size();	
	
	for (int i = 0; i < lim; ++i) {
		int v = grafo[curNode][i].first;
		if (v == prev) continue;
		if (sc == -1 || subsize[sc] < subsize[v]) {
			sc = v;
			ncost = grafo[curNode][i].second;
		}
	}
	
	if (sc != -1)
		HLD(sc, ncost, curNode);
	
	for (int i = 0; i < lim; ++i) {
		int v = grafo[curNode][i].first;
		if (v == prev || v == sc) continue;
		chainNo++;
		HLD(v, grafo[curNode][i].second, curNode);
	}
	return;
}

int LCA(int x, int y) {
	if (level[x] < level[y]) swap(x, y);
	
	for (int i = LN - 1; i >= 0; --i)
		if (level[x] - (1 << i) >= level[y])
			x = P[i][x];
	
	if (x == y) return x;
	
	for (int i = LN - 1; i >= 0; --i)
		if (P[i][x] != P[i][y]) {
			x = P[i][x];
			y = P[i][y];
		}
	
	return P[0][x];
}

void PreLCA(int n) {
	for (int j = 1; j < LN; ++j) 
		for (int i = 1; i <= n; ++i)
			P[j][i] = P[j - 1][P[j - 1][i]];
	return;
}

void DFS(int cur, int prev, int len) {
	level[cur] = len;
	P[0][cur] = prev;
	subsize[cur] = 1;
	int lim = grafo[cur].size();
	for (int i = 0; i < lim; ++i) { 
		int v = grafo[cur][i].first; 
		if (v == prev) continue;
		otherEnd[indexx[cur][i]] = v;
		DFS(v, cur, len + 1);
		subsize[cur] += subsize[v];
	}
	return;
}

void Limpia(int n) {
	for (int i = 0; i <= n; ++i) {
		grafo[i].clear();
		indexx[i].clear();
		chainHead[i] = -1;
		for (int j = 0; j < LN; ++j) P[j][i] = -1;
	}
	return;
}

//ST STUFF
void build_ST(int n, int l, int r) {
	if (l == r) {
		ST[n] = baseArray[l];
		return;
	}
	int lc (n << 1), rc = lc | 1, m = (l + r) >> 1;
	build_ST(lc, l, m);
	build_ST(rc, m + 1, r);
	ST[n] = max(ST[lc], ST[rc]);
	return;
}

void updateSegTree(int n, int L, int R, int i, int val) {
	if (L == R) {
		ST[n] = val;
		return;
	}
	int lc = n << 1, rc = lc | 1, m = (L + R) >> 1;
	if (i <= m) updateSegTree(lc, L, m, i, val);
	else updateSegTree(rc, m + 1, R, i, val);
	ST[n] = max(ST[lc], ST[rc]);
}

int querySegTree(int n, int L, int R, int l, int r) {
	if (R < l|| L > r) return 0;
	if (L >= l && R <= r) return ST[n];
	int lc = n << 1, rc = lc | 1, m = (L + R) >> 1;
	int lv = querySegTree(lc, L, m, l, r);
	int rv = querySegTree(rc, m + 1, R, l, r);
	return max(lv, rv);
}

int queryUp(int u, int v) {
	if (u == v) return 0;
	int lchain, rchain = chainInd[v], ans = -1;
	while (1) {
		lchain = chainInd[u];
		if (lchain == rchain) {
			if (u == v) break;
			int currAns = querySegTree(1, 1, ptr, posInBase[v] + 1, posInBase[u]);
			ans = max(ans, currAns);
			break;
		}
		int currAns = querySegTree(1, 1, ptr, posInBase[chainHead[lchain]], posInBase[u]);
		ans = max(ans, currAns);
		u = chainHead[lchain];
		u = P[0][u];
	}
	return ans;
}

int queryPath(int u, int v) {
	int lca = LCA(u, v);
	int a = queryUp(u, lca);
	int b = queryUp(v, lca);
	return max(a, b);
}

void Update(int i, int val) {
	int node = otherEnd[i];
	updateSegTree(1, 1, ptr, posInBase[node], val);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		ptr = 0;
		int n;
		cin >> n;
		Limpia(n);
		for (int i = 1; i < n; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			grafo[u].push_back(pii(v, c));
			grafo[v].push_back(pii(u, c));
			indexx[u].push_back(i);
			indexx[v].push_back(i);
		}
		DFS(1, 0, 0); //set subsize, depth, and parent for each node, 0 here is the root
		PreLCA(n);
		ptr = -1;
		chainNo = 1;
		HLD(1, 0, 0); //decompose tree and make baseArray
		build_ST(1, 1, ptr); //construct ST;
		string op;
		while (cin >> op) {
			if (op[0] == 'D') break;
			int u, v;
			cin >> u >> v;
			if (op[0] == 'Q') {
				cout << queryPath(u, v) << '\n';
				continue;
			}
			Update(u, v);
		}
	}
	return 0;
}