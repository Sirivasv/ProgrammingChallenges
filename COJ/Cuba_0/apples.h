#include <bits/stdc++.h>
using namespace std;
const int MAXN = 109;
int arr[MAXN];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int many;
	while (cin >> many) {
		for (int i = 0; i < many; ++i) cin >> arr[i];
		int sum = 0;
		for (int i = 0; i < many; ++i) sum += arr[i];
		int ans = 0;
		for (int i = 0; i < many; ++i) if ((sum - arr[i]) % 2 == 0) ans++;
		cout << ans << '\n';
	}
	return 0;
}