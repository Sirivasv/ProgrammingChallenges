#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;

int N, M, K, Q, Z;

double toCity[MAXN][MAXN], sendCard[MAXN][MAXN], memo[MAXN][MAXN], memo2[MAXN][MAXN];
int sentCards[MAXN];

int main() {
	
	int T;
	ifstream fin("trip.in");
	
	fin >> T;
	for (int nc = 0; nc < T; ++nc) {

		fin >> N >> M >> K >> Q >> Z;
		
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

		for (int i = 0; i < K; ++i) { fin >> sentCards[i]; }

		for (int i = 0; i < MAXN; ++i)
			for (int j = 0; j < MAXN; ++j) 
				memo2[i][j] = memo[i][j] = 0;

		double vari = 0;
		memo[0][0] = sendCard[0][sentCards[0]];
		for (int ncity = 1; ncity <= Q; ++ncity) {
			for (int i = 0; i < N; ++i) {
				for (int city = 0; city < N; ++city) {
					memo[i][ncity] += (memo[city][ncity - 1] * toCity[city][i] * sendCard[i][sentCards[ncity]]);
				}
			}
		}

		 		

		double varj = 0;
		memo2[Z][Q] = memo[Z][Q];
		for (int ncity = Q + 1; ncity < K; ++ncity) {
			for (int i = 0; i < N; ++i) {
				for (int city = 0; city < N; ++city) {
					memo[i][ncity] += (memo[city][ncity - 1] * toCity[city][i] * sendCard[i][sentCards[ncity]]);
					memo2[i][ncity] += (memo2[city][ncity - 1] * toCity[city][i] * sendCard[i][sentCards[ncity]]);
				}
			}
		}
		for (int i = 0; i < N; ++i) varj += memo2[i][K - 1];
		for (int i = 0; i < N; ++i) vari += memo[i][K - 1];

		printf("%.3lf\n", varj/vari);

	}	

	return 0;
} 