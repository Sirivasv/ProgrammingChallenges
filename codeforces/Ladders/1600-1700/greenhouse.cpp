#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 5009;

int arr[MAXN], dp[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, M, ans = 0;
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) {
		double xi;
		cin >> arr[i] >> xi;
	}
	
	for (int i = 0; i < N; ++i) {
		int tp = arr[i];
		for (int j = tp; j >= 1; --j)
			dp[tp] = max(dp[tp], dp[j] + 1);
		ans = max(ans, dp[tp]);
	}
	
	cout << (N - ans) << '\n';
	return 0;
}