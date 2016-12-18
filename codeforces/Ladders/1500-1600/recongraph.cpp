#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100009;

int degree[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	map<int, vector<int> > mp;
	set<int> vals;
	for (int i = 1; i <= N; ++i) {
		int dist;
		cin >> dist;
		mp[dist].push_back(i);
		vals.insert(dist);
	}
	int ok = 1, prev = -1;
	for (auto it : vals) {
		if ((it - prev) != 1)
			ok = 0;
		prev = it;
	}
	if (mp[0].size() != 1)
		ok = 0;
	if (!ok) {
		cout << "-1\n";
		return 0;
	}
	int lim = *vals.rbegin();
	vector<pii> Edges;
	for (int i = 1; i <= lim; ++i) {
		int plim = mp[i - 1].size();
		for (int j = 0; j < mp[i].size(); ++j) {
			degree[mp[i - 1][j % plim]]++;
			degree[mp[i][j]]++;
			Edges.push_back(pii(mp[i][j], mp[i - 1][j % plim]));
		}
	}
	for (int i = 1; i <= N; ++i)
		if (degree[i] > K)
			ok = 0;
	if (!ok) cout << "-1\n";
	else {
		cout << Edges.size() << '\n';
		for (auto it : Edges)
			cout << it.first << ' ' << it.second << '\n';
	}
	return 0;
}