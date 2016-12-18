#include <bits/stdc++.h>
using namespace std;

int Abs(int x) { return((x < 0)?(-x):(x)); }

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, x;
	cin >> N >> x;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		int v;
		cin >> v;
		sum += v;
	}
	sum = Abs(sum);
	int ans = sum / x;
	if ((sum % x) != 0)
		ans++;
	cout << ans << '\n';
}