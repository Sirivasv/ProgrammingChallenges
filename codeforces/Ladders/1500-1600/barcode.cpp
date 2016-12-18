#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;
const int MAXC = 3;

int N, M, li, ri;

int costcol[MAXN];

int memo[MAXN][MAXC];

int RangeCost(int a, int b) { return costcol[b] - costcol[a - 1]; }

int DP(int pos, int prec) {
	if (pos == (M + 1))
		return 0;
	if (memo[pos][prec] != -1)
		return memo[pos][prec];
	int res = 10000000;
	if (prec != 1) {
		for (int j = li; j <= ri; ++j)
			if ((pos + j - 1) <= M)
				res = min(res, DP(pos + j, 1) + (j * N) - RangeCost(pos, pos + j - 1));
			else
				break;
	}
	if (prec != 2) {
		for (int j = li; j <= ri; ++j)
			if ((pos + j - 1) <= M)
				res = min(res, DP(pos + j, 2) + RangeCost(pos, pos + j - 1));
			else
				break;
	}
	return memo[pos][prec] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXC; ++j)
			memo[i][j] = -1;
	
	cin >> N >> M >> li >> ri;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= M; ++j) {
			char ci;
			cin >> ci;
			if (ci == '.')
				costcol[j]++;
		}
	}
	
	for (int i = 1; i <= M; ++i)
		costcol[i] += costcol[i - 1];
	
	cout << DP(1, 0) << '\n';
	
	return 0;
}