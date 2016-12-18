#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30009;
const int LIM = 30000;
const int MAXI = 500;

int arr[MAXN], memo[MAXN][MAXI], OFF, N, M;

int DP(int pos, int len) {
	if (pos == LIM)
		return 0;
	if (memo[pos][len] != -1)
		return memo[pos][len];
	int nlen = len + OFF;
	
	int res1 = 0, res2 = 0, res3 = 0;
	if (((nlen - 1) >= 1) && ((pos + (nlen - 1)) <= LIM))
		res1 = DP(pos + (nlen - 1), (nlen - 1) - OFF) + arr[pos + (nlen - 1)];
	if ((pos + nlen) <= LIM)
		res2 = DP(pos + nlen, nlen - OFF) + arr[pos + nlen];
	if ((pos + (nlen + 1)) <= LIM)
		res3 = DP(pos + (nlen + 1), (nlen + 1) - OFF) + arr[pos + (nlen + 1)];
	//cout << len << ' ' << nlen << '\n';
	return memo[pos][len] = max(res1, max(res2, res3));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXI; ++j)
			memo[i][j] = -1;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int xi;
		cin >> xi;
		arr[xi]++;
	}
	OFF = M - 247;
	cout << (DP(M, M - OFF) + arr[M]) << '\n';
	
	return 0;
}