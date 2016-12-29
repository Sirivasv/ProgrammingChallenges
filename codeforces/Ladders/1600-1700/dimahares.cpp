#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3009;

int mat[5][MAXN];
int memo[MAXN][6][6], N;

int vuno[] = {1, 1, 2, 2, 3, 3};
int vdos[] = {2, 3, 1, 3, 2, 1};
int vtres[] = {3, 2, 3, 1, 1, 2};

int DP(int pos, int vi, int vj) {
	if (pos >= N) return 0;
	if (memo[pos][vi][vj] != -1)
		return memo[pos][vi][vj];
	int res = 0;
	for (int i = 0; i < 6; ++i) {
		int ans = 0;
		
		int lg = 0;
		if (vj > vi) lg++;
		if (vuno[i] > vdos[i]) lg++;
		ans += mat[lg][pos - 1];
		
		lg = 0;
		if ((vdos[i] > vtres[i]) && (pos != (N - 1))) lg++;
		if (vdos[i] > vuno[i]) lg++;
		ans += mat[lg][pos];
		
		if ((pos + 1) != (N - 1))
			ans += DP(pos + 2, vdos[i], vtres[i]);
		else {
			lg = 0;
			if (vdos[i] < vtres[i]) lg++;
			ans += mat[lg][pos + 1];
		}
		res = max(res, ans);
	}
	return memo[pos][vi][vj] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < N; ++j)
			cin >> mat[i][j];
	if (N == 1) {
		cout << mat[0][0] << '\n';
		return 0;
	}
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < 6; ++j)
			for (int k = 0; k < 6; ++k) memo[i][j][k] = -1;
	
	cout << DP(1, 2, 1) << '\n';
	return 0;
}