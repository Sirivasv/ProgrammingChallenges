#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10009;

int N, M;
double PX[MAXN];
double PY[MAXN];
double MINT = (10000 * 10000) + 1;

double Distance(int i, int j) {
	return ((PX[i] - PX[j]) * (PX[i] - PX[j])) + ((PY[i] - PY[j]) * (PY[i] - PY[j]));
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	while (cin >> N) {
		if (!N) break;
		for (int i = 0; i < N; ++i) cin >> PX[i] >> PY[i];
		MINT = (10000 * 10000);
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				MINT = min(MINT, Distance(i, j));
			}
		}
		if (MINT == (10000 * 10000)) cout << "INFINITY\n";
		else cout << fixed << setprecision(4) << sqrt(MINT) << '\n';
	}

	return 0;
}