#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 5009;

int N, M, K;

lli memo[MAXN][MAXN], arr[MAXN];

lli Range(int a, int b) {
	return (arr[b] - arr[a - 1]);
}

lli DP(int pos, int many_taken) {
	if (pos > N)
		return 0;
	if (many_taken == K)
		return 0;
	if (memo[pos][many_taken] != -1)
		return memo[pos][many_taken];
	lli res = DP(pos + 1, many_taken);
	if ((pos + M - 1) <= N)
		res = max(res, DP(pos + M, many_taken + 1) + Range(pos, pos + M - 1));
	return memo[pos][many_taken] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXN; ++j)
			memo[i][j] = -1;
	
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	
	cout << DP(1, 0) << '\n';
	
	return 0;
}