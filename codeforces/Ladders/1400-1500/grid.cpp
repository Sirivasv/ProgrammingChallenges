#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 509;

vector<pii> DtoN;

char mtr[MAXN][MAXN];

int dir_x[] = {1, -1, 0, 0};
int dir_y[] = {0, 0, 1, -1};

int N, M;

void BFS(pii o) {
	map<pii, int> vis;
	vis[o] = 1;
	DtoN.push_back(o);
	queue<pii> Q;
	Q.push(o);
	while (!Q.empty()) {
		pii nodeu = Q.front();
		Q.pop();
		int xi = nodeu.second;
		int yi = nodeu.first;
		for (int i = 0; i < 4; ++i) {
			int nx = xi + dir_x[i];
			int ny = yi + dir_y[i];
			pii v = pii(ny, nx);
			if ((ny >= 0) && (ny < N) && (nx >= 0) && (nx < M)) {
				if (vis.count(v) != 0)
					continue;
				if (mtr[ny][nx] != '.')
					continue;
				vis[v] = 1;
				DtoN.push_back(v);
				Q.push(v);
			}
		}
	}
	reverse(DtoN.begin(), DtoN.end());
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int K;
	pii origen;
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> mtr[i][j];
			if (mtr[i][j] == '.')
				origen = pii(i, j);
		}
		
	BFS(origen);
	
	int lim = DtoN.size();
	for (int i = 0; i < K; ++i) {
		int I = DtoN[i].first;
		int J = DtoN[i].second;
		mtr[I][J] = 'X';
	}
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cout << mtr[i][j];
		cout << '\n';
	}
	return 0;
}