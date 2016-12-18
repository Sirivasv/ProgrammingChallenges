#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

lli Dist(lli xi, lli yi, lli xj, lli yj) {
	return(((xj - xi) * (xj - xi)) + ((yj - yi) * (yj - yi)));
}

bool NoCabe(lli R, lli W, lli H) {
	if (((R + R) > W) || ((R + R) > H))
		return true;
	return false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	lli L, C, R1, R2;
	while (cin >> L >> C >> R1 >> R2) {
		if ((L + C + R1 + R2) == 0.0)
			break;
		lli DD = (R1 + R2) * (R1 + R2);
	
		if (NoCabe(R1, L, C) || NoCabe(R2, L, C)) {
			cout << "N\n";
			continue;
		}		
		
		if (Dist(R1, R1, L - R2, C - R2) < DD) {
			cout << "N\n";
		} else
			cout << "S\n";
	}
	return 0;
}