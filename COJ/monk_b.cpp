#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1009;
int memo[MAXN][MAXN], mtr[MAXN][MAXN], N;
int dir_x[] = {1, 0};

inline bool validc(int y, int x) {
	if (x < 0) return false;
	if (y > (N - 1)) {
		y = ((N << 1) - 1) - y - 1;
		y = (N - 1) - y;
		return ((x >= y) && (x <= N - 1));
	}
	return (x <= y);
}

int DP(int i, int j) {
	//cout << i << ' ' << j << '\n';
	if (memo[i][j]) return memo[i][j];
	if (i == ((N << 1) - 2)) return memo[i][j] = mtr[i][j];
	for (int k = 0; k < 2; ++k) {
		int ny = i + 1, nx = j + dir_x[k];
		if (validc(ny, nx)) memo[i][j] = max(DP(ny, nx), memo[i][j]);
	}
	return memo[i][j] += mtr[i][j];
}

int main() {
	int T, lim;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j <= i; ++j) {
				cin >> mtr[i][j];
				memo[i][j] = 0;
				//cout << i << ' ' << j << '\n'; 
			}
		lim = (N << 1);
		for (int i = N; i < lim; ++i)
			for (int j = 0, dif = i - (N - 1); j < (lim - i) - 1; ++j) {
				cin >> mtr[i][dif + j];
				memo[i][dif + j] = 0;
				//cout << i << ' ' << dif + j<< '\n'; 
			}
		cout << "Case " << nc << ": " << DP(0, 0) << '\n';
	}
	return  0;
}