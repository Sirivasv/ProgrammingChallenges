#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		int N, W;
		cin >> N >> W;
		int *arr = new int[N + 5];
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		sort(arr, arr + N);
		int ans = 0;
		for (int i = 0; i < N; ++i) {
			if ((W - arr[i]) >= 0) {
				ans++;
				W -= arr[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}