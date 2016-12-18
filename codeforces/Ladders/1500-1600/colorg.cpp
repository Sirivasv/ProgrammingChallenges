#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

vector<int> color[MAXN];
vector<int> grafo[MAXN];

int mcolor[MAXN], vis[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int c;
		cin >> c;
		color[c].push_back(i);
		mcolor[i] = c;
	}
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		if (mcolor[u] == mcolor[v])
			continue;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}
	
	int mats = -1, ans;
	for (int i = 0; i < N; ++i) {
		int k = mcolor[i];
		if (vis[k])
			continue;
		vis[k] = 1;
		set<int> mnc;
		for (int j = 0; j < color[k].size(); ++j) {
			int u = color[k][j];
			for (int l = 0; l < grafo[u].size(); ++l) {
				int v = grafo[u][l];
				mnc.insert(mcolor[v]);
			}
		}
		//cout << k << ' ' << mnc.size() << '\n';
		if (((int)mnc.size()) >= mats) {
			if (((int)mnc.size()) > mats)
				ans = k;
			mats = (int)mnc.size();
			ans = min(ans, k);
		}
	}
	cout << ans << '\n';
	return 0;
}