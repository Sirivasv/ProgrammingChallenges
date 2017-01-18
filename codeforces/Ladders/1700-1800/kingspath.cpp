#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;
const int INF = 1000000;

int dir_x[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dir_y[] = {-1, -1, -1, 0, 1, 1, 1, 0};

map<pii, int> NID;

int dist[MAXN], vis[MAXN];
vector<int> grafo[MAXN];


void BFS() {
	int lim = NID.size(); 
	for (int i = 1; i <= lim; ++i) {
		vis[i] = 0;
		dist[i] = INF;
	}
	
	dist[1] = 0;
	vis[1] = 1;
	
	queue<int> Q;
	Q.push(1);
	
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i];
			if (vis[v]) continue;
			vis[v] = 1;
			dist[v] = dist[u] + 1;
			Q.push(v);
		}
	}
	
}


int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	pii ori, dest;
	int N;
	
	cin >> ori.first >> ori.second >> dest.first >> dest.second;
	
	NID[ori] = 1; NID[dest] = 2;
	
	int cnt = 3;
	
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int ri, ai, bi;
		cin >> ri >> ai >> bi;
		for (int j = ai; j <= bi; ++j) {
			pii pos = pii(ri, j);
			if (NID.find(pos) == NID.end())
				NID[pos] = cnt++;
		}		
	}
	
	for (const auto& it : NID) {
		int cx = it.first.first;
		int cy = it.first.second;
		int u = it.second;
		for (int i = 0; i < 8; ++i) {
			pii puv = pii(cx + dir_x[i], cy + dir_y[i]);
			if (NID.find(puv) == NID.end()) continue;
			grafo[u].push_back(NID[puv]);
			grafo[NID[puv]].push_back(u);
		}
 	}
	
	BFS();
	
	cout << ((dist[2] != INF)?(dist[2]):(-1)) << '\n';
	
	return 0;
}