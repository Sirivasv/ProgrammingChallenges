#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 200;
const int MAXM = (1 << 8);

lli memo[MAXN][MAXN][MAXM];
int flag[MAXN][MAXN][MAXM], ID;

lli mat[MAXN][MAXN];
int Xi[10], Yi[10];
int R, C, N, Sx, Sy;

lli DP(int i, int j, int msk) {
	if (flag[i][j][msk] == ID) return memo[i][j][msk];
	flag[i][j][msk] = ID;

	lli res = mat[i][j];
	for (int k = 0; k < N; ++k) {
		if (msk & (1 << k)) continue;
		int xj = Xi[k];
		int yj = Yi[k];
		int nmsk = msk | (1 << k);
		//+x +y
		if (((i + xj) < R) && ((j + yj) < C)) 
			res = max(res, DP(i + xj, j + yj, nmsk) + mat[i][j]);
		//+x -y
		if (((i + xj) < R) && ((j - yj) >= 0))
			res = max(res, DP(i + xj, j - yj, nmsk) + mat[i][j]);
		//-x -y
		if (((i - xj) >= 0) && ((j - yj) >= 0))
			res = max(res, DP(i - xj, j - yj, nmsk) + mat[i][j]);
		//-x +y
		if (((i - xj) >= 0) && ((j + yj) < C))
			res = max(res, DP(i - xj, j + yj, nmsk) + mat[i][j]);
	}
	return memo[i][j][msk] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> R >> C >> N;
		cin >> Sx >> Sy;
		for (int i = 0; i < N; ++i) cin >> Xi[i];
		for (int i = 0; i < N; ++i) cin >> Yi[i];
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				cin >> mat[i][j];
		ID++;
		cout << DP(Sx, Sy, 0) << '\n';
	}
	return 0;
}