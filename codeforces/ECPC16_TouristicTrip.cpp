#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;

double toCity[MAXN][MAXN], memo[MAXN][MAXN], sendCard[MAXN][MAXN];
int postCard[MAXN];

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	int T, N, M, K, Z, Q;

	ifstream fin("trip.in");

	fin >> T;
	for (int nc = 0; nc < T; ++nc) {
		fin >> N >> M >> K >> Q >> Z;

		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				memo[i][j] = 0;
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				fin >> toCity[i][j];
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				fin >> sendCard[i][j];
			}
		}

		for (int i = 0; i < K; ++i) {
			fin >> postCard[i];
		}

		memo[0][0] = 1.0;

		Q--;
		for (int i = 1; i <= Q; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < N; ++k) {
					memo[i][j] += memo[i - 1][k] * toCity[k][j];
				}
				if (sendCard[j][postCard[i]] <= 0.0) {
					memo[i][j] = 0;
				}
				// memo[i][j] *= sendCard[j][postCard[i]];
			}
		}

		cout << memo[Q][Z] << '\n';

	}

	return 0;
}