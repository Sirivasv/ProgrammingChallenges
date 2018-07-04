#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int FULL_MASK = (1 << 20);

double mat[MAXN][MAXN];
double memo[FULL_MASK];
int vis[FULL_MASK], ID, N, CURRID;

double DP(int msk) {

	if ((msk & (1 << CURRID)) == 0) return 0;
	if ((msk & (1 << CURRID)) == msk) return 1;
	if (vis[msk] == ID) return memo[msk];

	vis[msk] = ID;

	double cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if ((msk & (1 << i)) && (msk & (1 << j))) {
				cnt += 1.0;
			}
		}
	}

	cnt = 1.0 / cnt;
	double res = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if ((msk & (1 << i)) && (msk & (1 << j))) {
				res += cnt * mat[i][j] * DP(msk & ~(1 << j));
				res += cnt * mat[j][i] * DP(msk & ~(1 << i));
			}
		}
	}	

	return memo[msk] = res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> mat[i][j];
			}
		}
		cout << "Case " << nc << ":";
		for (int i = 0; i < N; ++i) {
			cout << ' ';
			CURRID = i;
			ID++;
			cout << fixed << setprecision(9) << DP((1 << N) - 1);
		}
		cout << '\n';
	}

	return 0;
}