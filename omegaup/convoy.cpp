#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1009; 
int PT, N;
double L, S[MAXN], W[MAXN], memo[MAXN];

double DP(int id) {
	if (id >= N) return 0.0;
	if (memo[id] != -1.0) return memo[id];
	memo[id] = DP(id + 1) + (L/S[id]);
	double mins = S[id];
	int sum = W[id];
	for (int i = id + 1; (i < N) && (sum <= PT); ++i) {
		sum += W[i];
		if (sum > PT) break;
		mins = min(S[i], mins);
		memo[id] = min(memo[id], DP(i + 1) + (L/mins));
	}
	return memo[id];
}

void Limpia() {
	for (int i = 0; i <= N; ++i)
		memo[i] = -1.0;
}

int main() {
	while (cin >> PT >> L >> N) {
		if (!(PT + ((int)L) + N)) break;
		Limpia();
		L *= 60.0;
		for (int i = 0; i < N; ++i) 
			cin >> W[i] >> S[i];
		cout << fixed;
		cout << setprecision(1) << DP(0) << '\n';
	}
	return 0;
}