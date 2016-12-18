#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200009;

vector<int> grafo[MAXN];

int inDegree[MAXN];
char color[MAXN];
vector<int> ciclo;

void Limpia(int N) {
	for (int i = 0; i < N; ++i) {
		grafo[i].clear();
		inDegree[i] = 0;
	}
}

void DetectarCiclo(int u, int p) {
	color[u] = ciclo.empty()? 'G': 'N';
	for (int v : grafo[u]) {
		if (v == p) continue;
		if (ciclo.empty() && color[v] == 'G')
			color[v] = 'A', ciclo.push_back(v), 
			color[u] = 'R', ciclo.push_back(u);
		if (color[v] != 'B') continue;
		DetectarCiclo(v, u);
		if (color[u] == 'G' && color[v] == 'R')
			color[u] = 'R', ciclo.push_back(u);
	}
	if (color[u] == 'G') color[u] = 'N';
}

vector< vector<int> > DetectarCiclos(int n) {
	vector< vector<int> > ciclos;
	for (int i = 0; i < n; ++i)
		color[i] = 'B';
	for (int u = 0; u < n; ++u) {
		if (color[u] != 'B') continue;
		ciclo.clear(); DetectarCiclo(u, u);
		reverse(ciclo.begin(), ciclo.end());
		if (ciclo.size() > 0) ciclos.push_back(ciclo);
	}
	return ciclos;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, cnt = 0;
	while (cin >> N >> M) {
		
		if (!(N + M))
			break;
		
		Limpia(cnt);
		
		map<int, int> mp; 
		
		cnt = 0;
		
		int flag = 1;
		
		for (int i = 0; i < M; ++i) {
			int u, v;
			cin >> u >> v;
			if (!mp.count(u))
				mp[u] = cnt++;
			if (!mp.count(v))
				mp[v] = cnt++;
			u = mp[u];
			v = mp[v];
			if (find(grafo[u].begin(), grafo[u].end(), v) == grafo[u].end()) {
				grafo[u].push_back(v);
				grafo[v].push_back(u);
				inDegree[v]++;
				inDegree[u]++;
				if (inDegree[v] >= 3)
					flag = 0;
				if (inDegree[u] >= 3)
					flag = 0;
			}
		}
		
		if (!flag) {
			cout << "N\n";
			continue;
		}
		
		vector< vector<int> > cic = DetectarCiclos(cnt);
		if ((cic.size() == 0) || (((cic.size() == 1) && (cic[0].size() == N))) ) {
			cout << "Y\n";
			continue;
		}
		
		cout << "N\n";
		
	}
	return 0;
}