#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	int sum = 0;
	int last = 0;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int xi;
		cin >> xi;
		sum += (last - xi);
		if (sum < 0) {
			ans += -sum;
			sum = 0;
		}
		last = xi;
	}
	cout << ans << '\n';
	return 0;
}