#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

string S;
int N, K, memo[MAXN], flag[MAXN], ID;

int DP(int id) {
	if (id == N) return 0;
	if (flag[id] == ID) return memo[id];
	flag[id] = ID;
	int res = DP(id + 1) + 1;
	int has_rep = 0;
	for (int i = id + 1; i < N; ++i) {
		has_rep |= (S[i - 1] == S[i]);
		if ((i - id + 1) > K) break;
		if (has_rep) res = min(res, DP(i + 1) + 1);
	}
	return memo[id] = res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		cin >> S;
		ID++;
		cout << DP(0) - 1 << '\n';
	}
	return 0;
}