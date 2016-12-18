#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109;

int mtr[5][MAXN][MAXN];
int vis[MAXN][MAXN];
int dir_x[] = {1, -1, 0, 0};
int dir_y[] = {0, 0, 1, -1};

int main() {
	int N, R, C, K;
	while (cin >> N >> R >> C >> K) {
		if (!(N || R || C || K))
			break;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cin >> mtr[0][i][j];
			}
		}
		for (int nb = 1; nb <= K; ++nb) {
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j)
					vis[i][j] = 0;
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					for (int k = 0; k < 4; ++k) {
						int ni = i + dir_y[k];
						int nj = j + dir_x[k];
						if (((ni >= 0) && (ni < R)) && ((nj >= 0) &&(nj < C))) {
							if (mtr[(nb - 1) & 1][ni][nj] == ((mtr[(nb - 1) & 1][i][j] + 1) % N)) {
								mtr[nb & 1][ni][nj] = mtr[(nb - 1) & 1][i][j];
								vis[ni][nj] = 1;
							}
						}
					}
				}
			}
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j)
					if (vis[i][j] == 0)
						mtr[nb & 1][i][j] = mtr[(nb - 1) & 1][i][j];
		}
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (j)
					cout << ' ';
					cout << mtr[(K) & 1][i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}