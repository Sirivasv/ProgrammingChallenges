#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

double dp[MAXN][MAXN][MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int r, s, p;
	cin >> r >> s >> p;
	dp[r][s][p] = 1.0;
	for (int i = r; i >= 0; --i)
		for (int j = s; j >= 0; --j)
			for (int k = p; k >= 0; --k) {
				if ((i + j + k) == 0) break;
				if ((i == r) && (j == s) && (k == p)) continue;
				double *val = &dp[i][j][k];
				double den = ((i + 1) * j) + ((i + 1) * k) + (k * j);
				if (((i + 1) <= r) && (k)) *val += (((double)((i + 1) * k)) / den) * dp[i + 1][j][k];
				den = (i * (j + 1)) + (i * k) + (k * (j + 1));
				if (((j + 1) <= s) && (i)) *val += (((double)(i * (j + 1))) / den) * dp[i][j + 1][k];
				den = (i * j) + ((k + 1) * i) + ((k + 1) * j);
				if (((k + 1) <= p) && (j)) *val += (((double)((k + 1) * j)) / den) * dp[i][j][k + 1];
			}
	double sum = 0;
	cout << fixed << setprecision(10) << '\n';
	for (int i = 1; i <= r; ++i) sum += dp[i][0][0];
	cout << sum << ' ';
	sum = 0;
	for (int i = 1; i <= s; ++i) sum += dp[0][i][0];
	cout << sum << ' ';
	sum = 0;
	for (int i = 1; i <= p; ++i) sum += dp[0][0][i];
	cout << sum << '\n';
	return 0;
}