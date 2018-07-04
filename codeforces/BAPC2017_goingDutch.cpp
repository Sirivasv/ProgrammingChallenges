#include <bits/stdc++.h>
using namespace std; 

const int FULL_MASK = 1 << 20;
const int MAXN = 20;

int memo[FULL_MASK], vis[FULL_MASK], value[MAXN], ID, N;

int dp(int bitMask) {
	if (bitMask == 0) { return 0; }
	if (vis[bitMask] == ID) { return memo[bitMask]; }
	vis[bitMask] = ID;

	int currMax = 0;
	int balance = 0;

	for (int i = 0; i < N; ++i) {
		if (bitMask & (1 << i)) {
			currMax = max(currMax, dp(bitMask & ~(1 << i)));
			balance += value[i];
		}
	}

	int balaceIsZero = (balance == 0);

	return memo[bitMask] = currMax + balaceIsZero;
}

int main() {
	cin.tie(); ios_base::sync_with_stdio(0);

	int M;

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int xi, yi, pi;
		cin >> xi >> yi >> pi;
		value[xi] -= pi;
		value[yi] += pi;
	}

	ID++;
	cout << (N - dp((1 << N) - 1)) << '\n';

	return 0;
}