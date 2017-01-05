#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXV = (1 << 18) + 5;

int cub[20], m, fullm, cnt, mdig[10];

lli memo[MAXV][109], N;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> m;
		
	while (N) {
		cub[cnt++] = N % 10LL;
		mdig[N % 10LL]++;
		N /= 10LL;
	}
	
	fullm = (1 << cnt) - 1;
	
	for (int i = 0; i < cnt; ++i)
		if (cub[i] != 0)
			memo[1 << i][cub[i] % m] = 1;
	
	for (int i = 1; i < fullm; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!memo[i][j]) continue;
			for (int k = 0; k < cnt; ++k)
				if (!(i & (1 << k)))
					memo[i | (1 << k)][(j * 10 + cub[k]) % m] += memo[i][j];
		}
	}
	
	lli res = memo[fullm][0];
	
	for (int i = 0; i < 10; ++i)
		for (int j = 2; j <= mdig[i]; ++j)
			res = (res / ((lli)j));
	
	cout << res << '\n';
	
	return 0;
}