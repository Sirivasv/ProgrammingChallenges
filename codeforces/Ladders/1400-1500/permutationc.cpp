#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5009;

int arr[MAXN];

bitset<MAXN> seen;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	seen.set();
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		seen[a] = 0;
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans += seen[i];
	cout << ans << '\n';
	return 0;
}