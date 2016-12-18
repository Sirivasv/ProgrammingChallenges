#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000;

int memo[MAXN], arr[5];

int DP(int l) {
	if (l == 0)
		return 0;
	if (memo[l] != -2)
		return memo[l];
	int tresp = -1;
	for (int i = 0; i < 3; ++i)
		if ((l - arr[i]) >= 0)
			if (DP(l - arr[i]) != -1)
				tresp = max(tresp, DP(l - arr[i]) + 1);
	return memo[l] = tresp;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i)
		memo[i] = -2;
	int N;
	cin >> N;
	for (int i = 0; i < 3; ++i)
		cin >> arr[i];
	cout << DP(N) << '\n';
	return 0;
}