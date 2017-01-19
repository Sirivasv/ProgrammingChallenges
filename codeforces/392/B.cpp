#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef pair<lli, lli> pii;

const int MAXN = 109;

int arr[10], N;
int memo[MAXN][9][9][9];

string s;

//R 1
//Y 2
//B 3
//G 4

int DP(int pos, int p1, int p2, int p3) {
	if (pos == N) return 1;
	if (memo[pos][p1][p2][p3] != -1)
		return memo[pos][p1][p2][p3];
	int res = 0;
	if (s[pos] == 'R') {
		if ((p1 == 1) || (p2 == 1) || (p3 == 1)) res = 0;
		else res = DP(pos + 1, 1, p1, p2);
	}
	if (s[pos] == 'Y') {
		if ((p1 == 2) || (p2 == 2) || (p3 == 2)) res = 0;
		else res = DP(pos + 1, 2, p1, p2);
	}
	if (s[pos] == 'B') {
		if ((p1 == 3) || (p2 == 3) || (p3 == 3)) res = 0;
		else res = DP(pos + 1, 3, p1, p2);
	}
	if (s[pos] == 'G') {
		if ((p1 == 4) || (p2 == 4) || (p3 == 4)) res = 0;
		else res = DP(pos + 1, 4, p1, p2);
	}
	if (s[pos] == '!') {
		for (int i = 1; i < 5; ++i) {
			if ((p1 == i) || (p2 == i) || (p3 == i)) continue;
			res |= DP(pos + 1, i, p1, p2);
		}
	}
	return memo[pos][p1][p2][p3] = res;
}

void REDP(int pos, int p1, int p2, int p3) {
	if (pos == N) return;
	if (s[pos] == 'R') {
		REDP(pos + 1, 1, p1, p2);
		return;
	}
	if (s[pos] == 'Y') {
		REDP(pos + 1, 2, p1, p2);
		return;
	}
	if (s[pos] == 'B') {
		REDP(pos + 1, 3, p1, p2);
		return;
	}
	if (s[pos] == 'G') {
		REDP(pos + 1, 4, p1, p2);
		return;
	}
	if (s[pos] == '!') {
		for (int i = 1; i < 5; ++i) {
			if ((p1 == i) || (p2 == i) || (p3 == i)) continue;
			if (DP(pos + 1, i, p1, p2)) {
				arr[i]++;
				REDP(pos + 1, i, p1, p2);
				return;
			}
		}
	}
	return;
}

int main() {
	
	cin.tie(0); ios_base::sync_with_stdio(0);
	//scanf("%d", &N);
	
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < 9; ++j)
		for (int k = 0; k < 9; ++k)
		for (int l = 0; l < 9; ++l) memo[i][j][k][l] = -1;

	
	cin >> s;
	N = s.size();
	DP(0, 0, 0, 0);
	REDP(0, 0, 0, 0);
	
	cout << arr[1] << ' ' << arr[3] << ' ' << arr[2] << ' ' << arr[4] << '\n';
	
	//printf("%lld\n", arr[0]);
	
	return 0;
}