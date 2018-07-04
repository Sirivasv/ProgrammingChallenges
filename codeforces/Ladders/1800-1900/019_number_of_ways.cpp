#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500009;

typedef long long lli;

lli arr[MAXN];
unordered_map<lli, lli> seen(MAXN / 3);

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	seen[arr[1]] = 1;
	lli ans = 0;
	for (int i = 2; i < N; ++i) {
		lli flt = arr[N] - arr[i];
		if (arr[i] == (flt << 1)) {
			if (seen.count(arr[i] - flt)) {
				ans += seen[arr[i] - flt];
			}
		}
		seen[arr[i]]++;
	}
	cout << ans << '\n';
	return 0;
}