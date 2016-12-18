#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int arr[MAXN];

int main () {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + N);
	int ans = 0, asum = 0;
	for (int i = N- 1; i >= 0; --i) {
		ans++;
		asum += arr[i];
		if (asum > (sum - asum))
			break;
	}
	cout << ans << '\n';
	return 0;
}