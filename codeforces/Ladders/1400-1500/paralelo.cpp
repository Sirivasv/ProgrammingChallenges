#include <bits/stdc++.h>
using namespace std;

typedef double lli;

int main() {
	lli xi, yi, zi, a, b, c;
	cin >> xi >> yi >> zi;
	c = sqrt(yi / (xi / zi));
	b = yi / c;
	a = xi / b;
	cout << ((long long)((a + b + c) * ((double)4LL))) << '\n';
	return 0;
}