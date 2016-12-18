#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> pci;

vector< vector<pci> > grafo;
set<int> nodeswherewords;
char str[85];
int totn;

void add() {
	int u = 0;
	int lim = strlen(str);
	for (int i = 0; i < lim; ++i) {
		int found = 0, vf;
		for (int j = 0; j < grafo[u].size(); ++j) {
			char c = grafo[u][j].first;
			int v = grafo[u][j].second;
			if (c == str[i]) {
				found = 1;
				vf = v;
			}
		}
		if (found)
			u = vf;
		else {
			grafo[u].push_back(pci(str[i], grafo.size()));
			u = grafo.size();
			grafo.push_back(vector<pci>());
		}
	}
	nodeswherewords.insert(u);
}

void Sum(int u = 0, int dist = 1) {
	int val = (((grafo[u].size() > 1) && u) || (nodeswherewords.find(u) != nodeswherewords.end()));
	if (nodeswherewords.find(u) != nodeswherewords.end())
		totn += dist;
	for (int i = 0; i < grafo[u].size(); ++i)
		Sum(grafo[u][i].second, dist + val);
	return;
}

int main() {
	int N;
	while (scanf("%d", &N) != EOF) {
		grafo.clear();
		nodeswherewords.clear();
		totn = 0;
		grafo.push_back(vector<pci>());
		for (int i = 0; i < N; ++i) {
			scanf("%s", str);
			add();
		}
		Sum();
		printf("%.2lf\n", (((double)totn)/ ((double)N)));
	}
	return 0;
}