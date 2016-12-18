#include <bits/stdc++.h>
using namespace std;
const int MAXN = 509;
const int INF = 10000000;
int ki, acum[MAXN], memo[MAXN][MAXN];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int S;
	cin >> S;
	for (int i = 1; i <= S; ++i) {
		cin >> ki;
		acum[i] = acum[i - 1] + ki;
	}
	for (int size = 1; size <= S; ++size)
		for (int l = 1; (l + size - 1) <= S; ++l) {
			int r = l + size - 1;
			if (l == r) { 
				memo[l][r] = 0;
				continue;
			}
			memo[l][r] = INF;
			for (int k = l; k < r; ++k) 
				memo[l][r] = min(memo[l][r], memo[l][k] + memo[k + 1][r] + max(acum[k] - acum[l - 1], acum[r] - acum[k]));
		}
	cout << memo[1][S] << '\n'; 
	return 0;
}