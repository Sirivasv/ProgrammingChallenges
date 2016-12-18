#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int mans = -1000000009;
	for (int i = 0; i < N; ++i) {
		int f, t;
		cin >> f >> t;
		mans = max(mans, ((t > K)?(f - (t - K)):(f)));
	}
	cout << mans << '\n';
	return 0;
}