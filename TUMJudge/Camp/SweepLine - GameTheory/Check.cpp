#include <bits/stdc++.h>
using namespace std; 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int N;
		cin >> N;
		int v = 0;
		int n = 0;
		for (int i = 0; i < N; ++i) {
			int a, b;
			cin >> a >> b;
			n = (max(a, b) - min(a, b)) - 1;
			v ^= n;
		}
		cout << "Case #" << nc << ": ";
		if (!v) 
			cout << "black\n";
		else 
			cout << "white\n";
	}
	return 0;
}