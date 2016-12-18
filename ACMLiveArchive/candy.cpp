#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100009;

int vis[MAXN];
int ID;
int memo[MAXN];

int DP(int pos, vector<int>& v) {
	if (pos >= v.size())
		return 0;
	if (vis[pos] == ID)
		return memo[pos];
	vis[pos] = ID;
	return memo[pos] = max(DP(pos + 1, v), DP(pos + 2, v) + v[pos]);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int R, C;
	while (cin >> R >> C) {
		if (!(R || C))
			break;
		vector<int> Tv(R);
		vector<int> CC(C);
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cin >> CC[j];
			}
			ID++;
			Tv[i] = DP(0, CC);
		}
		ID++;
		cout << DP(0, Tv) << '\n';
	}
	return 0;
}