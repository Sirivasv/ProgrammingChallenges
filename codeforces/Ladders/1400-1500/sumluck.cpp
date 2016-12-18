#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;

int memo[MAXN];

int DP(int pos) {
	if (pos == 0)
		return 0;
	if (memo[pos] != -1)
		return memo[pos];
	int val1 = MAXN;
	if ((pos - 4) >= 0)
		val1 = DP(pos - 4) + 1;
	int val2 = MAXN;
	if ((pos - 7) >= 0)
		val2 = DP(pos - 7) + 1;
	return memo[pos] = min(val1, val2);
}

void REDP(int pos) {
	if (pos == 0)
		return;
	int val1 = MAXN;
	if ((pos - 4) >= 0) {
		val1 = DP(pos - 4) + 1;
		if (memo[pos] == val1) {
			cout << '4';
			REDP(pos - 4);
			return;
		}
	}
	int val2 = MAXN;
	if ((pos - 7) >= 0) {
		val2 = DP(pos - 7) + 1;
		if (memo[pos] == val2) {
			cout << '7';
			REDP(pos - 7);
			return;
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i)
		memo[i] = -1;
	int N;
	cin >> N;
	int procres = DP(N);
	if (procres >= MAXN)
		cout << "-1\n";
	else {
		REDP(N);
		cout << '\n';
	}
	return 0;
}