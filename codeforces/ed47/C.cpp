#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli sum = 0;

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	int M;
	lli N;

	cin >> N >> M;

	lli sumMax = ((N - 1LL) * (N)) >> 1;

	lli sumMin = (((N >> 1) + 1LL) * (N >> 1)) >> 1;
		sumMin <<= 1;
	if ((N & 1) == 0) {
		sumMin -= N >> 1;
	}


	for (int i = 0;i < M; ++i) {
		lli xi, di;
		cin >> xi >> di;

		sum += (xi * N);

		if (di < 0) {
			sum += (di * sumMin);
		} else {
			sum += (di * sumMax);
		}

	}

	double res = double(sum) / double(N);
	cout << fixed << setprecision(9) << res << '\n';

	return 0;
}