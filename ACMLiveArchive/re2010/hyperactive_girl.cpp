#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 109;
const int MOD = 100000000;
const int MAXNP = 209;

pii activity[MAXN];

map<int, int> atimes;

int m, n;
int memo[MAXN][MAXNP];

bool Can(int candidate, int actual, int lst) {
	if (actual == 0)
		return atimes[activity[candidate].first] == 0;
	return (atimes[activity[candidate].first] > lst) && 
		(atimes[activity[candidate].first] <= atimes[activity[actual].second]) && 
			(atimes[activity[candidate].second] > atimes[activity[actual].second]);
}

int DP(int id, int lst) {
	if (atimes[activity[id].second] >= atimes[m])
		return 1;
	if (memo[id][lst] != -1)
		return memo[id][lst];
	int found = 0, sum = 0;
	for (int i = 1; i <= n; ++i)
		if (Can(i, id, lst)) {
			int nlst = max(atimes[activity[id].second], atimes[activity[i].first]);
			sum = (sum + DP(i, nlst)) % MOD;
			found = 1;
		}
	if (!found)
		return memo[id][lst] = 0;
	return memo[id][lst] = sum;
}

void Limpia() {
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j < MAXNP; ++j)
			memo[i][j] = -1;
	atimes.clear();
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> m >> n) {
		if (!(m + n))
			break;
		Limpia();
		for (int i = 1; i <= n; ++i) {
			cin >> activity[i].first >> activity[i].second;
			atimes[activity[i].first]++;
			atimes[activity[i].second]++;
		}
		atimes[0] = atimes[m] = 1;
		int npos = 0;
		for (auto it = atimes.begin(); it != atimes.end(); it++) 
			it->second = npos++;
		cout << DP(0, 0) << '\n';
	}
	return 0;
}