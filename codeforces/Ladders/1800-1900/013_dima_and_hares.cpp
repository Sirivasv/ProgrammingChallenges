#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3009;

int memo[MAXN][3], vis[MAXN][3], joy[MAXN][5];
int N;

int DP(int id, int flg) {
	if (vis[id][flg]) return memo[id][flg];
	vis[id][flg] = 1;
	if (id == N)
		return memo[id][flg] = joy[id][flg];
	return memo[id][flg] = max(DP(id + 1, 1) + joy[id][flg], DP(id + 1, 0) + joy[id][flg + 1]);
}


int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> joy[i][0];
	for (int i = 1; i <= N; ++i) cin >> joy[i][1];
	for (int i = 1; i <= N; ++i) cin >> joy[i][2];

	cout << DP(1, 0) << '\n';

	return 0;
}