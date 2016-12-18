#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXP = 70;

lli memo[MAXP][3][MAXP];
int vis[MAXP][3][MAXP];
int bnum[MAXP], lim, ID;

lli DP(int pos, int fl, int sum) {
	if (pos == lim)
		return sum;
	if (vis[pos][fl][sum] == ID)
		return memo[pos][fl][sum];
	vis[pos][fl][sum] = ID;
	lli res = 0;
	if (fl) {
		res += DP(pos + 1, fl, sum + 1) + DP(pos + 1, fl, sum);
	} else {
		res += DP(pos + 1, fl | (bnum[pos]), sum);
		if (bnum[pos])
			res += DP(pos + 1, fl, sum + 1);
	}
	return memo[pos][fl][sum] = res;
}

void ntob(lli x) {
	lim = 0;
	while (x) {
		bnum[lim++] = x & 1;
		x >>= 1;
	}
	reverse(bnum, bnum + lim);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli A, B;
	while (cin >> A >> B) {
		ntob(B);
		ID++;
		lli tos = DP(0, 0, 0);
		ntob(A - 1);
		ID++;
		tos -= DP(0, 0, 0);
		cout << tos << '\n';
	}
	return 0;
}