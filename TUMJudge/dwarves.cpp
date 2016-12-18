#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10009;

char vis[MAXN];
vector<int> grafo[MAXN];

bool CycleD(int u) {
	vis[u] = 'G';
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (vis[v] == 'G')
			return true;
		if ((vis[v] == 'B') && (CycleD(v)))
			return true;
	}
	vis[u] = 'N';
	return false;
}

bool HasCycle(int n) {
	for (int i = 0; i < n; ++i)
		vis[i] = 'B';
	for (int i = 0; i < n; ++i)
		if ((vis[i] == 'B') && (CycleD(i)))
			return true;
	return false;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	map<string, int> dwarves;
	int N, id = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s, ss;
		int u, v;
		cin >> s;
		if (!dwarves.count(s))
			dwarves[s] = id++;
		u = dwarves[s];
		cin >> ss;
		cin >> s;
		if (!dwarves.count(s))
			dwarves[s] = id++;
		v = dwarves[s];
		if (ss[0] == '<')
			grafo[u].push_back(v);
		else
			grafo[v].push_back(u);
	}
	if (HasCycle(id))
		cout << "impossible\n";
	else
		cout << "possible\n";
	return 0;
}