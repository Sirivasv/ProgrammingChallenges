#include <bits/stdc++.h>
using namespace std;
const int MAXN = 509;
int memo[MAXN][MAXN];
string s, ss;

inline int DP() {
	int n = s.size(), m = ss.size();
	for (int i = 0; i <= m; ++i) memo[i][0] = i;
	for (int i = 0; i <= n; ++i) memo[0][i] = i;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) 
			memo[i][j] = min(min(memo[i - 1][j] + 1, memo[i][j - 1] + 1), memo[i - 1][j - 1] + (s[i - 1] != ss[j - 1]));
	return memo[m][n];
}
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> s >> ss;
	cout << DP() << '\n';
	return 0;
} 