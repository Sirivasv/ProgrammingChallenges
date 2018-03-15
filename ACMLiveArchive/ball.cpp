#include <bits/stdc++.h>
#define op__ cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;

typedef long long lli;

const int MAXN = 1009;
const lli INF = (1LL << 60);
const lli MINF = -INF;

int ID;
int FLAG[MAXN][MAXN];
lli memo[MAXN][MAXN];
lli acum[MAXN][MAXN];

int N;

lli DP(int i, int j) {
	if ((i > N) || (j > N)) return 0;
	
	if (FLAG[i][j] == ID) return memo[i][j];
	FLAG[i][j] = ID;
	
	lli res = DP(i, j + 1) + acum[i][j];
	res = max(res, DP(i + 1, j));
	
	return memo[i][j] = res;
}

int main(){
	op__;
	
	while (cin >> N) {
		if (!N) break;

		for (int i = 1; i <= N + 10; ++i)
			for (int j = 1; j <= N + 10; ++j) acum[i][j] = 0;
		
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= i; ++j) cin >> acum[N - j + 1][i - j + 1];

		for (int j = 1; j <= N; ++j)
			for (int i = N; i >= 1; --i) acum[i][j] += acum[i + 1][j];

		ID++;
		cout << DP(1, 1) << '\n';
	}
	return 0;
}