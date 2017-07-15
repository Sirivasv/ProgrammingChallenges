//Div 2 B - Proba
#include <bits/stdc++.h>
using namespace std;

const double ERR = 1e-12;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	double A, B, C, D;
	double PM1, PM2;
	double CM1, CM2;

	cin >> A >> B >> C >> D;

	PM1 = A / B; PM2 = C / D;
	CM1 = 1.0 - PM1; CM2 = 1.0 - PM2;

	double curr_val = 1.0;
	double res = 0;

	for (; curr_val > ERR ;) {
		res += PM1 * curr_val;
		curr_val *= CM1 * CM2;
	}

	cout << fixed << setprecision(7) << res << '\n';

	return 0;
}