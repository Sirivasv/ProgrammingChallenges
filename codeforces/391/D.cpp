#include <bits/stdc++.h>
using namespace std;

const int MAXN = 80;
const int MAXV = (1 << 15);

int memo[MAXN][MAXV];

int DP(int pos, int mask) {
	if (pos >= N) {
		int ok = 1;
		int id = 14;
		while ((!((mask) & (1 << id))) && (id >= 0)) {
			id--;
		}
		while (id >= 0) {
			ok &= ((mask & (1 << id)) != 0);
			id--;
		} 
		return ok;
	}
	if (memo[pos][mask] != -1)
		return memo[pos][mask];
	int res = 0;
	int sum = 0;
	for (int i = pos; i < N; ++i) {
		sum *= 2;
		sum += arr[i] - '0';
		if (sum >= 15) break;
		res += DP(i + 1, mask | (1 << sum))
	}
}

int main() {
	
	return 0;
}