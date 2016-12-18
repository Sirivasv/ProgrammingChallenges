#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	double cfinal = 0.0;
	double a, b;
	double cfinalt = 100.0 * 10.0;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		cfinal += a * b;
		while (a) {
			a -= 1.0;
			cout << '*';
		}
		cout << '\n';
	}
	int cfint = (((cfinal * 10.0)/cfinalt));
	if (cfint < 6.0) {
		cout << "0\n";
		cout << ":(\n";
	} else {
		cout << cfint << '\n';
		cout << ":)\n";
	}
	return 0;
}