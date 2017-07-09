#include<bits/stdc++.h>
using namespace std;

typedef long long lli;

int N;
lli M;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;

	lli sum = 0, ans = 0;

	for (int i = 1; i < N; ++i) {
		lli a, b;
		cin >> a >> b;
		sum -= b;
		sum += a;
		if (M <= sum) ans++;
	}

	cout << ans << '\n';

	return 0;
}
