#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MAXN = 59;
const int MAXI = 309;
const int INF = (1 << 30);

int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};

bitset<MAXN> vis[MAXN]; 
int reg[MAXN][MAXN], dist[MAXI][MAXI], parent[MAXI];
char mtr[MAXN][MAXN];
piii Ari[90005];
int idar;

int R, C, color = 301;

int Find(int u) {
	if(parent[u] == u)
		return u;
	return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
	parent[Find(u)] = Find(v);
}

bool MismoC(int u, int v) {
	return Find(u) == Find(v);
}

void Fill(int I, int J, int c) {
	vis[I][J] = 1;
	reg[I][J] = c;
	queue<pii> Q;
	Q.push(pii(I, J));
	while (!Q.empty()) {
		int xi = Q.front().second;
		int yi = Q.front().first;
		Q.pop();
		for (int k = 0; k < 4; ++k) {
			int nx = xi + dir_x[k];
			int ny = yi + dir_y[k];
			if (((nx >= 0) && (nx < C)) && ((ny >= 0) && (ny < R))) {
				if (vis[ny][nx])
					continue;
				if (mtr[ny][nx] != 'X')
					continue;
				vis[ny][nx] = 1;
				reg[ny][nx] = c;
				Q.push(pii(ny, nx));
			}
		}
	} 
}

void Limpia() {
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			vis[i][j] = 0;
			reg[i][j] = 0;
		}
	for (int i = 0; i <= color; ++i) {
		for (int j = 0; j <= color; ++j)
			dist[i][j] = INF;
	}
	color = 1;
	idar = 0;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	//scanf("%d", &T);
	while (T--) {
		cin >> R >> C;
		//scanf("%d%d", &R, &C);
		Limpia();
		
		for (int i = 0; i < R; ++i) {
			//getchar();
			for (int j = 0;j < C; ++j)
				cin >> mtr[i][j];
			//scanf("%c", &mtr[i][j]);
		}
			
		for (int i = 0; i < R; ++i)
			for (int j = 0;j < C; ++j) {
				if (vis[i][j])
					continue;
				if (mtr[i][j] == 'X')
					Fill(i, j, color++);
				else
					vis[i][j] = 1;
			}
		
		/*for (int i = 0; i < R; ++i) {
			for (int j = 0;j < C; ++j) {
				cout << reg[i][j];
			}
			cout << '\n';
		}*/
		
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (reg[i][j] == 0)
					continue;
				int c_ = reg[i][j];
				for (int k = 0; k < R; ++k) {
					for (int l = 0; l < C; ++l) {
						if ((reg[k][l] != c_) && (reg[k][l])){
							//cout << c_ << ' ' << reg[k][l] << '\n';
							dist[c_][reg[k][l]] = min(dist[c_][reg[k][l]], (int)((fabs(i - k)) + (fabs(j - l))));
						}
					}
				}
			}
		}
		for(int i = 1; i < color; ++i)
			for (int j = 1; j < color; ++j) {
				//cout << i << ' ' << j <<  ' ' << dist[i][j] << '\n';
				Ari[idar++] = piii(dist[i][j] - 1, pii(i, j));
			}
		for(int i = 1; i < color; ++i) parent[i] = i;
		sort(Ari, Ari + idar);
		int sum = 0;
		for (int i = 0; i < idar; ++i) {
			int p = Ari[i].first;
			int u = Ari[i].second.first;
			int v = Ari[i].second.second;
			if (MismoC(u, v))
				continue;
			Union(u, v);
			sum += p;
			//cout << sum << '\n';
		}
		cout << sum << '\n';
		//printf("%d\n", sum);
	}
	return 0;
}