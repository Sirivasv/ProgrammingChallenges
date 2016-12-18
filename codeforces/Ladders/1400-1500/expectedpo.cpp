#include <bits/stdc++.h>
using namespace std;

double LogPot(double xb, int pot) {
	double res = 1.0;
	for (; pot; pot >>= 1) {
		if (pot & 1)
			res *= xb;
		xb *= xb;
	}
	return res;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M;
	cin >> M >> N;
	double ans = 0;
	for (int i = 1; i <= M; ++i)
		ans += ((double)i) * (LogPot(((double)i) / ((double)M), N) - LogPot(((double)(i - 1)) / ((double)M), N));
	cout << fixed << setprecision(6) << ans << '\n';
	return 0;
}