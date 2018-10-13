#include <bits/stdc++.h>
using namespace std;

int main() {

	cin.tie(0); ios_base::sync_with_stdio(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		long long N, K, V;
		cin >> N >> K >> V;

		vector<string> vi(N);
		vector<int> isInAns(N, 0);
		for (int j = 0; j < N; ++j) {
			cin >> vi[j];
		}

		long long res = (K * (V - 1LL)) % N;
		cout << "Case #" << ( i + 1 ) << ":";
		
		for (int j = 0; j < K; ++j) {
			isInAns[(j + res) % N] = 1;
		}
		for (int j = 0; j < N; ++j) {
			if (isInAns[j]) {
				cout << " " << vi[j];
			}
		}
		cout << '\n';
	}

	return 0;
}