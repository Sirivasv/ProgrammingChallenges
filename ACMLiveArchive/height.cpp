#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109;

int omtr[MAXN][MAXN], R, C, vis[MAXN][MAXN];

int dir_x[] = {1, -1, 0, 0};
int dir_y[] = {0, 0, 1, -1};

void Fill(int yi, int xi, int ci) {
	vis[yi][xi] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = yi + dir_y[i], nx = xi + dir_x[i];
		if (((((ny >= 0) && (ny < R)) && ((nx >= 0) && (nx < C))) && (omtr[ny][nx] == ci)) && (!vis[ny][nx])) {
			vis[ny][nx] = 1;
			Fill(ny, nx, ci);
		}
	}
}

int FloodFill() {
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			vis[i][j] = 0;
	int res = 0;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if (!vis[i][j]) {
				Fill(i, j, omtr[i][j]);
				res++;
			}	
	return res;
}

int tmpr[MAXN][MAXN];

void Rotate() {
	for (int i = 0; i < R; ++i)
		for (int j= 0; j < C; ++j)
			tmpr[j][R - i - 1] = omtr[i][j];
	swap(R, C);
	for (int i = 0; i < R; ++i)
		for (int j= 0; j < C; ++j)
			omtr[i][j] = tmpr[i][j];
}

int Process() {
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			vis[i][j] = 0;
	int ans = 1;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if ((!vis[i][j]) && ((j + 1) < C)){
				int ni = i, nj = j;
				vis[ni][nj] = 1;
				if (!(omtr[ni][nj] < omtr[ni][nj + 1]))
					continue;
				ans++;
				while (omtr[ni][nj] < omtr[ni][nj + 1]) {
					vis[ni][nj] = 1;
					ni++;
					if (ni == R)
						break;
					if (omtr[ni - 1][nj] >= omtr[ni][nj + 1])
						break;
					if (omtr[ni][nj] >= omtr[ni - 1][nj + 1])
						break;
				}
			}
		}
	}
	return ans;
}

int main() {
	//cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> R >> C) {
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j) 
				cin >> omtr[i][j];
		int ans = 0;
		ans++; // la de abajo
		ans += FloodFill();// la de arriba
		ans += Process(); //left
		Rotate();
		ans += Process(); //front
		Rotate();
		ans += Process(); //right 
		Rotate();
		//for (int i = 0; i < R; ++i, cout << '\n') for (int j = 0; j < C; ++j) cout << omtr[i][j] << ' ';
		ans += Process(); //back 
		cout << ans << '\n';
	}
	return 0;
}