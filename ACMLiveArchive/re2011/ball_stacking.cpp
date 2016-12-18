#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

long long acum[MAXN][MAXN];
long long memo[MAXN][MAXN];
long long arr[MAXN][MAXN];
int N;

void Limpia() {
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= N; ++j)
			memo[i][j] = -1, arr[i][j] = 0;
}

long long DP(int row, int col) {
	if (row == 0)
		return 0;
	if (memo[row][col] != -1)
		return memo[row][col];
	if (col == N)
		return memo[row][col] = max(acum[row][col], DP(row - 1, col));
	return memo[row][col] = max(DP(row - 1, col), DP(row, col + 1) + acum[row][col]);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> N) {
		if (!N)
			break;
		Limpia();
		for (int i = 1; i <= N; ++i) 
			for (int j = 1; j <= i; ++j)
				cin >> arr[i - j + 1][j];
		//for (int i = 1; i <= N; ++i, cout << '\n') 
			//for (int j = 1; j <= N; ++j)
				//cout << arr[i][j] << ' ';
		for (int j = 1; j <= N; ++j)
			for (int i = 1; i <= N; ++i) 
				acum[i][j] = acum[i - 1][j] + arr[i][j];
		//for (int i = 1; i <= N; ++i, cout << '\n') 
			//for (int j = 1; j <= N; ++j)
				//cout << acum[i][j] << ' ';
		cout << DP(N, 1) << '\n';
	}
	return 0;
}