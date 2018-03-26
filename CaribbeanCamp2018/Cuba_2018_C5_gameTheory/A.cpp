#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
 
lli getN(lli xi) {
	return ( (xi * (xi - 1LL)) >> 1LL);
}
 
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	int T;
	cin >> T;
	for (int nc = 0; nc < T; ++nc) {
		lli N;
		cin >> N;
		
		int final = 1LL;
		int inicial = 0;
		int res = 0;
		
		for (int i = 1; i < N; ++i) {
			int j = N - i;
			if ((i+j) == N) {
				//cout << "A: " << i << " B: " << j << '\n';
				lli totar = (getN(i) + getN(j) + 1LL);
				//cout << "Tot: " << totar << '\n'; 
				final &= (totar & 1LL);
				if (i == 1) {
					inicial = (totar & 1LL);
				}
				res += (totar & 1LL);
				//cout << ((totar & 1LL)?("Alice\n"):("Bob\n"));
			}
		} 
		if (final) {
			cout << "Alice\n";
		} else if (res == 0) {
			cout << "Bob\n";
		} else if (inicial) {
			cout<< "Bob\n";
		} else {
			cout << "Alice\n";
		}
		
	}
	
	return 0;
}
