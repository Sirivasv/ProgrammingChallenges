#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
const int MAXP = 40;
const int MAXO = 10;

int memo[MAXN][MAXN][MAXP][MAXO];
int ans[MAXN][MAXN];

int N, nk[MAXN];

int dir_y[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dir_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void DP(int yi, int xi, int pos, int ori) {
	if (memo[yi][xi][pos][ori]) return;
	if (pos == N) return;
	memo[yi][xi][pos][ori] = 1;
	ans[yi][xi] = 1;
	for (int i = 1; i < nk[pos]; ++i) {
		yi += dir_y[ori];
		xi += dir_x[ori];
		ans[yi][xi] = 1;
	}
	DP(yi + dir_y[(ori - 1 + 8) % 8], xi + dir_x[(ori - 1 + 8) % 8], pos + 1, (ori - 1 + 8) % 8);
	DP(yi + dir_y[(ori + 1) % 8], xi + dir_x[(ori + 1) % 8], pos + 1, (ori + 1) % 8);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> nk[i];
	DP(100, 100, 0, 2);
	int res = 0;
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			res += ans[i][j];
		cout << res << '\n';
	return 0;
}