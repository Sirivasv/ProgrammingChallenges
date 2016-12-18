#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;
const int INF = (1 << 30);
typedef pair<int, int> pii;
vector<pii> grafo[MAXN];

int distU[MAXN];
int distN[MAXN];
int distZ[MAXN];

void DijkstraU(int o) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, o)); 
	distU[o] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int p = pq.top().first; 
		pq.pop();
        if (distU[u] < p) continue;        
        for (int i = 0; i < grafo[u].size(); ++i) {
            p = grafo[u][i].second;
            int v = grafo[u][i].first;
            if (distU[u] + p < distU[v]) {
                distU[v] = distU[u] + p;
                pq.push(pii(distU[v], v));
            }
        }
    }
    return;
}

void DijkstraN(int o) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, o)); 
	distN[o] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int p = pq.top().first; 
		pq.pop();
        if (distN[u] < p) continue;        
        for (int i = 0; i < grafo[u].size(); ++i) {
            p = grafo[u][i].second;
            int v = grafo[u][i].first;
            if (distN[u] + p < distN[v]) {
                distN[v] = distN[u] + p;
                pq.push(pii(distN[v], v));
            }
        }
    }
    return;
}

void Dij(int o, int N) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, o)); 
	distZ[o] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        int p = pq.top().first; 
		pq.pop();
        if (distZ[u] < p) continue;        
        for (int i = 0; i < grafo[u].size(); ++i) {
            p = grafo[u][i].second;
            int v = grafo[u][i].first;
            if (distZ[u] + p < distZ[v]) {
				
				if ((distU[N] == (p + (distU[u] + distN[v]))) || (distU[N] == (p + (distN[u] + distU[v]))))
					continue;
				
                distZ[v] = distZ[u] + p;
                pq.push(pii(distZ[v], v));
            }
        }
    }
    return;
}

void Limpia(int N) {
	for (int i = 0; i <= N; ++i) {
		distU[i] = INF;
		distN[i] = INF;
		distZ[i] = INF;
		grafo[i].clear();
	}
	return;
}

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N, M;
	
	while (cin >> N >> M) {
		if (!(N + M))
			break;
		
		Limpia(N);
		int u, v, c;
		for (int i = 0; i < M; ++i) {
			cin >> u >> v >> c;
			grafo[u].push_back(pii(v, c));
			grafo[v].push_back(pii(u, c));
		}
		
		DijkstraU(1);
		DijkstraN(N);
		
		Dij(1, N);
		
		if (distZ[N] == INF)
			cout << "Do'oh!\n";
		else
			cout << distZ[N] << '\n';
		
	}
	
	return 0;
}