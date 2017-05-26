#include <bits/stdc++.h>
using namespace std;

int Abs(int x) { return ((x >= 0)?(x):(-x)); } 

int main() {
	int cp, np;
	cin >> cp >> np;
	int clockW, clockA;
	
	if (np > cp) {
		clockW = np - cp;
		clockA = (cp + 360) - np;
	} else {
		clockW = (np + 360) - cp;
		clockA = cp - np;
	}

	if (clockA < clockW) cout << -clockA << '\n';
	else cout << clockW << '\n';

	return 0;
}