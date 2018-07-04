#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

string mat[MAXN];
char vis[MAXN][MAXN];
int mats[MAXN][MAXN];
int dir_x[] = {0, 1, -1, 0};
int dir_y[] = {1, 0, 0, -1};
map<char, char> nxt;

int N, M, hasCycle;

int DFS(int yi, int xi) {
	vis[yi][xi] = 1;
	int curr_mx = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = yi + dir_y[i], nx = xi + dir_x[i];
		if ((ny >= 0) && (ny < N) && (nx >= 0) && (nx < M) && (nxt[mat[yi][xi]] == mat[ny][nx])) { 
			if (vis[ny][nx] == 1) {
				hasCycle = 1;
				return 0;
			}
			int cnt = (mat[ny][nx] == 'A');
			if (!vis[ny][nx]) DFS(ny, nx);
			cnt += mats[ny][nx];
			if (hasCycle) return 0;
			curr_mx = max(curr_mx, cnt);
		}
	}
	mats[yi][xi] = curr_mx;
	vis[yi][xi] = 2;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	nxt['D'] = 'I';
	nxt['I'] = 'M';
	nxt['M'] = 'A';
	nxt['A'] = 'D';

	cin >> N >> M;

	for (int i = 0; i < N; ++i) cin >> mat[i];

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if ((mat[i][j] == 'D') && (!vis[i][j])) {
				DFS(i, j);
				cnt = max(mats[i][j], cnt);
				if (hasCycle) {
					cout << "Poor Inna!\n";
					return 0;
				}
			}
		}
	}
	if (!cnt) {
		cout << "Poor Dima!\n";
	} else {
		cout << cnt << '\n';
	}
	return 0;
}