#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000009;

int cst[15];

int memo[MAXN];

int DP(int val) {
	if (val == 0)
		return 0;
	if (memo[val] != -1)
		return memo[val];
	int ans = 0;
	for (int i = 9; i >= 1; --i) 
		if ((val - cst[i]) >= 0)
			ans = max(ans, DP(val - cst[i]) + 1);
	return memo[val] = ans;
}

void REDP(int val) {
	if (val == 0)
		return;
	for (int i = 9; i >= 1; --i) 
		if (((val - cst[i]) >= 0) && ((DP(val - cst[i]) + 1) == memo[val])) {
			cout << i;
			REDP(val - cst[i]);
			break;
		}
	return;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	for (int i = 0; i < MAXN; ++i) 
		memo[i] = -1;
	int v;
	cin >> v;
	for (int i = 1; i <= 9; ++i)
		cin >> cst[i];
	
	int res = DP(v);
	if (!res) {
		cout << "-1\n";
		return 0;
	} 
	
	REDP(v);
	cout << '\n';
	return 0;
}