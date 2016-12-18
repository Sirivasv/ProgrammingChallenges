#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int arr[MAXN], barr[MAXN], memo[MAXN];

int N, M;

int DP(int pos) {
	if (pos == M)
		return 0;
	if (memo[pos] != -100000)
		return memo[pos];
	return memo[pos] = max(DP(pos + 1) + arr[pos], DP(pos + 1));
}

int  main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i)
		memo[i] = -100000;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> barr[i];
	for (int i = 0; i < M; ++i) {
		int sum = 0;
		int I, J;
		cin >> I >> J;
		for (int j = I; j <= J; ++j)
			sum += barr[j];
		arr[i] = sum;
		//cout << arr[i] << '\n';
	}
	cout << DP(0) << '\n';
	return 0;
}