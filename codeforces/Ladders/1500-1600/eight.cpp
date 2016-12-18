#include <bits/stdc++.h>
using namespace std;

const int MAXN = 109;
const int MAXL = 10;

int ok = 0, memo[MAXN][5][MAXL];
string s;

int DP(int pos, int lleva, int sum) {
	if (((pos == s.size()) && (lleva >= 1)) || (lleva == 3)) {
		ok |= ((sum % 8) == 0);
		return ((sum % 8) == 0);
	}
	if (pos == s.size())
		return 0;
	if (memo[pos][lleva][sum] != -1)
		return memo[pos][lleva][sum];
	int res = 0;
	if ((lleva == 0) && (s[pos] == '0'))
		res |= DP(pos + 1, lleva, sum);
	else
		res |= (DP(pos + 1, lleva, sum) || DP(pos + 1, lleva + 1, ((sum * 10) + (s[pos] - '0')) % 8));
	return memo[pos][lleva][sum] = res;
}

void REDP(int pos, int lleva, int sum) {
	if (((pos == s.size()) && (lleva >= 1)) || (lleva == 3))
		return;
	if ((lleva == 0) && (s[pos] == '0'))
		REDP(pos + 1, lleva, sum);
	else {
		if (DP(pos + 1, lleva, sum) == DP(pos, lleva, sum))
			REDP(pos + 1, lleva, sum);
		else {
			cout << s[pos];
			REDP(pos + 1, lleva + 1, ((sum * 10) + (s[pos] - '0')) % 8);
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < 5; ++j)
			for(int k  = 0; k < MAXL; ++k)
				memo[i][j][k] = -1;
	cin >> s;
	DP(0, 0, 0);
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '0') {
			cout << "YES\n0\n";
			return 0;
		}
	cout << ((ok)?("YES\n"):("NO\n"));
	if (ok) {
		REDP(0, 0, 0);
		cout << '\n';
	}
	return 0;
}