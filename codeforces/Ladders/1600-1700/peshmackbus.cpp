#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

const int MAXN = 1009;

lli ans[MAXN][MAXN];

int main() {	
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	lli n, d, k;
	
	//cin >> n >> k >> d;
	scanf("%lld%lld%lld", &n, &k, &d);
	
	int ok = 0;
	
	lli b = k;
	for (int i = 0; i < d; ++i) {
		if (b >= n) {
			ok = 1;
			break;
		}
		b *= k;
	}
	if (!ok) {
		//cout << "-1\n";
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < d; ++j) ans[i][j] = ans[i - 1][j];
		for (int j = d - 1; j >= 0; j--) { // suma a patita
			ans[i][j] = (ans[i][j] + 1) % k;
			if (ans[i][j]) break;
		}
	}
	for (int i = 0; i < d; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j) printf(" "); //cout << ' ';
			printf("%lld", ans[j][i] + 1); //cout << ans[j][i] + 1;
		}
		printf("\n"); //cout << '\n';
	}
 	return 0;
}