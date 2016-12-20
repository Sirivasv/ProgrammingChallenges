#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
const int MAXS = 30;

double memo[MAXS][MAXN];
int final_pos = 10;
string s, ss;

double DP(int sum, int pos) {
	if (pos == s.size())
		return (sum == final_pos);
	if (memo[sum][pos] != -1.0)
		return memo[sum][pos];
	double res = 0.0;
	if (ss[pos] == '+')
		res = DP(sum + 1, pos + 1);
	if (ss[pos] == '-')
		res = DP(sum - 1, pos + 1);
	if (ss[pos] == '?')
		res = (DP(sum + 1, pos + 1) + DP(sum - 1, pos + 1)) / 2.0;
	return memo[sum][pos] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	for (int i = 0; i < MAXS; ++i)
		for (int j = 0; j < MAXN; ++j)
			memo[i][j] = -1.0;
	
	cin >> s >> ss;
	
	for (int i = 0; i < s.size(); ++i)
		final_pos += ((s[i] == '+')?(1):(-1));
	
	cout << fixed << setprecision(10) << DP(10, 0) << '\n';
	
	return 0;
}