#include <bits/stdc++.h>
using namespace std;

//Ternary searchi minimum

int F(double xi) { // modify
	return 1;
}

int main() {
	double ini = 0, fin = 1e9;
	for (int it = 0; it < 100; ++it) {
		double mid1 = lo + (hi - lo) / 3.0;
		double mid1 = hi - (hi - lo) / 3.0;
		ans = min(F(mid1), ans);
		ans = min(F(mid2), ans);
		if (F(mid1) >= F(mid2)) lo = mid1;
		else hi = mid2;
	}
	cout << ans << '\n';
	return 0;
}