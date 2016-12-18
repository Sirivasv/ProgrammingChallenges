#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const int MAXN = 1009;

lli beauties[MAXN], wits[MAXN];

vector< vector<int> > GirlBlocks;

int parent[MAXN];
lli memo[MAXN][MAXN];
int vis[MAXN][MAXN];
int N, M, ID;
lli W;

int Find(int u) { return ((parent[u] == u)?(u):(parent[u] = Find(parent[u]))); }

int Union(int u, int v) { parent[Find(u)] = Find(v); }

lli DP(int pos, lli pe) {
	if ((pos == GirlBlocks.size()) || (pe == 0))
		return 0;	
	if (vis[pos][pe] == ID)
		return memo[pos][pe];
	vis[pos][pe] = ID;
	lli res = DP(pos + 1, pe);
	lli sumw = 0, sumb = 0;
	for (int i = 0; i < GirlBlocks[pos].size(); ++i) {
		int gid = GirlBlocks[pos][i];
		sumw += wits[gid];
		sumb += beauties[gid];
		if ((pe - wits[gid]) < 0LL)
			continue;
		res = max(res, DP(pos + 1, pe - wits[gid]) + beauties[gid]);
	}
	if ((pe - sumw) >= 0LL)
		res = max(res, DP(pos + 1, pe - sumw) + sumb);
	return memo[pos][pe] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	cin >> N >> M >> W;
	for (int i = 0; i <	N; ++i) {
		parent[i] = i;
		cin >> wits[i];
	}
	for (int i = 0; i < N; ++i)
		cin >> beauties[i];
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (Find(u) == Find(v))
			continue;
		Union(u, v);
	}
	map<int, int> block;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (!block.count(Find(i))) {
			block[Find(i)] = cnt++;
			GirlBlocks.push_back(vector<int>());
		}
		GirlBlocks[block[Find(i)]].push_back(i);
	}
	ID++;
	cout << DP(0, W) << '\n';
	return 0;
}