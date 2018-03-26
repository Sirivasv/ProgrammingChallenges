#include <bits/stdc++.h>
using namespace std;

const int LIM = 1 << 20;
const int MAXN = 30;

double memo[LIM];
double probc[MAXN];
double sum;
double ci[MAXN];
double Ei[MAXN];

int completeMSK; 
int N;

double dp(int msk) {
	if (msk == (completeMSK)) return 0.0;
	if (memo[msk] != -1.0) return memo[msk];
	memo[msk] = 0;
	
	double probB = 0.0;
	double probC = 0.0;
	for (int i = 0; i < N; ++i) {
		if (msk & (1 << i)) probC += ci[i];
		else probB += ci[i];
	}

	for (int i = 0; i < N; ++i) {
		if (msk & (1 << i)) continue;
		memo[msk] += (ci[i] / probB) * ((sum / (sum - probC)) + dp(msk | (1 << i)));
	}
	return memo[msk];
}

int main() {

	for (int i = 0; i < LIM; ++i) memo[i] = -1.0;

	cin >> N;
	completeMSK = (1 << N) - 1;

	sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> ci[i];
		sum += ci[i];
	}

	cout << fixed << setprecision(9) << dp(0) << '\n';

	return 0;
}