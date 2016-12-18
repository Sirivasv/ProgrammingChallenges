#include <bits/stdc++.h>
using namespace std;

typedef pair<int, double> pid;

const int MAXS = 1009;

double memo[MAXS][MAXS];

pid Food[MAXS];

int N, M;

double DP(int id, int left) {
	if ((id == N) || (left == 0))
		return 0.0;
	if (memo[id][left] != -1.0)
		return memo[id][left];
	double mats = 0;
	double many;
	double noms = Food[id].second;
	int lim = min(left, Food[id].first);
	for (int i = 0; i <= lim; ++i) {
		many = i;
		mats = max(mats, DP(id + 1, left - i) + (many * noms));
	}
	return memo[id][left] = mats;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	
	for (int i = 0; i < MAXS; ++i)
		for (int j = 0; j < MAXS; ++j)
			memo[i][j] = -1.0;
	
	string s;
	
	for (int i = 0; i < N; ++i) 
		cin >> s >> Food[i].first >> Food[i].second;
	
	cout << fixed << setprecision(6) << DP(0, M) << '\n';
	return 0;
}