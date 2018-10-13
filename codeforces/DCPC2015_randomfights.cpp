#include <bits/stdc++.h>
using namespace std;

typedef double Double;

const int MAXN = 25;
const int FULL_MASK = (1 << 20);

Double mat[MAXN][MAXN];
Double memo[FULL_MASK];
int N;
vector<int> vec[MAXN];

void DP(int cnt) {
	
	if (cnt == 1) return; 

	for (int nv = 0; nv < vec[cnt].size(); ++nv) {
		Double prob = 2.0 / (Double(cnt) * (Double(cnt) - 1.0));
		int msk = vec[cnt][nv];
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				if ((msk & (1 << i)) && (msk & (1 << j))) {
					memo[msk & ~(1 << j)] += memo[msk] * prob * mat[i][j];
					memo[msk & ~(1 << i)] += memo[msk] * prob * mat[j][i];
				}
			}
		}
	}

	DP(cnt - 1);
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
			vec[i].clear();
			vec[i + 1].clear();
		}


		for (int i = 0; i < FULL_MASK; ++i) {
			memo[i] = 0;
			int subcnt = 0;
			for (int j = 0; j < N; ++j) {
				if (i & (1 << j)) {
					subcnt++;
				}
			}
			if (i <= ((1 << N) - 1)) {
				vec[subcnt].push_back(i);
			}
		}

		memo[(1 << N) - 1] = 1.0;
		DP(N);

		cout << "Case " << nc << ":";
		for (int i = 0; i < N; ++i) {
			cout << ' ';
			cout << fixed << setprecision(6) << memo[(1 << i)];
		}
		cout <<  '\n';
	}

	return 0;
}