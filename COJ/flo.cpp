#include <bits/stdc++.h>
using namespace std;

const int MAXN = 209;
const int INF = 1000000000;

int dist[MAXN][MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int p = 0; p < T; ++p) {
		if (p) cout << '\n';
		int N, M;
		cin >> N >> M;
		for (int j = 1; j <= N; ++j)
			for (int k = 1; k <= N; ++k)
				if (j == k) dist[j][k] = 0;
				else dist[j][k] = INF;
		for (int i = 0; i < M; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			dist[a][b] = min(dist[a][b], c);
			dist[b][a] = min(dist[b][a], c);
			dist[a][b] = min(dist[a][b], dist[b][a]);
			dist[b][a] = dist[a][b];
		}

		for (int k = 1; k <= N; ++k)
			for (int a = 1; a <= N; ++a)
				for (int b = 1; b <= N; ++b) {
					if ((a == b) || (a == k) || (b == k)) continue;
					dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
					dist[b][a] = min(dist[b][a], dist[b][k] + dist[k][a]);
					dist[a][b] = min(dist[a][b], dist[b][a]);
					dist[b][a] = dist[a][b];
				}
		int Q;
		cin >> Q;
		for (int i = 0; i < Q; ++i) {
			int a, b;
			cin >> a >> b;
			if (dist[a][b] == INF) cout << "-1\n";
			else cout << dist[a][b] << '\n';
		}
	}	

	return 0;
}