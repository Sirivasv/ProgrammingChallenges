#include <bits/stdc++.h>
using namespace std;

int Abs(int x) { return ((x < 0)?(-x):(x)); }

int main() {
	int lim = 5;
	int xi, yi;
	for (int i = 1; i <= lim; ++i)
		for (int j = 1; j <= lim; ++j) {
			int n;
			cin >> n;
			if (n == 1) {
				xi = j;
				yi = i;
			}
		}
	cout << Abs(3 - xi)  + Abs(3 - yi) << '\n';
	return 0;
}