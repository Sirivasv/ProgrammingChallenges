#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

int memo[20][20][MAXN];

int M;
string s;

int DP(int mint, int last_e, int pos) {
	if (pos == M)
		return 1;
	if (memo[mint][last_e][pos] != -1)
		return memo[mint][last_e][pos];
	int ok = 0;
	for (int i = 0; i < 10; ++i)
		if ((s[i] == '1') && ((i + 1) > mint) && ((i + 1) != last_e))
			ok |= DP((i + 1) - mint, i + 1, pos + 1);
	return memo[mint][last_e][pos] = ok;
} 

void REDP(int mint, int last_e, int pos) {
	if (pos == M)
		return;
	for (int i = 0; i < 10; ++i)
		if ((s[i] == '1') && ((i + 1) > mint) && ((i + 1) != last_e)) {
			if (DP((i + 1) - mint, i + 1, pos + 1)) {
				cout << ' ' << (i + 1);
				REDP((i + 1) - mint, i + 1, pos + 1);
				break;
			}
		}
	return;
} 

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 20; ++j)
			for (int k = 0; k < MAXN; ++k)
				memo[i][j][k] = -1;
			
	cin >> s >> M;
	
	int ok = 0;
	
	for (int i = 0; i < 10; ++i)
		if (s[i] == '1')
			ok |= DP(i + 1, i + 1, 1);
	
	if (!ok) {
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	for (int i = 0; i < 10; ++i)
		if (s[i] == '1') {
			if (DP(i + 1, i + 1, 1)) {
				cout << (i + 1);
				REDP(i + 1, i + 1, 1);
				break;
			}
		}
	cout << '\n';
	
	return 0;
}