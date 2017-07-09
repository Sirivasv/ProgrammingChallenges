#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int memo[MAXN][MAXN], corteH[MAXN], corteV[MAXN], limH, limV;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> M >> N;
	limV = M - 1;
	for (int i = 0; i < limV; ++i) cin >> corteV[i];
	sort(corteV, corteV + limV, greater<int>());
	limH = N - 1;
	for (int i = 0; i < limH; ++i) cin >> corteH[i];
	sort(corteH, corteH + limH, greater<int>());
	memo[limH][limV] = 0;
	for (int i = limV - 1; i >= 0; --i) memo[limH][i] = memo[limH][i + 1] + (N * corteV[i]);
	for (int i = limH - 1; i >= 0; --i) memo[i][limV] = memo[i + 1][limV] + (M * corteH[i]);
	for (int i = limV - 1; i >= 0; --i)
		for (int j = limH - 1; j >= 0; --j) memo[j][i] = min(memo[j + 1][i] + ((i + 1) * corteH[j]), memo[j][i + 1] + ((j + 1) * corteV[i]));
	cout << memo[0][0] << '\n';
	return 0;
} 