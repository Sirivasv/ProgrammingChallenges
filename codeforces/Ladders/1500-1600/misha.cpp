#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ter;

const int MAXN = 1 << 17;

vector<pii> Aristas;

pii Nodes[MAXN];
int pos[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int N;
	cin >> N;
	queue<int> Q;
	for (int i = 0; i < N; ++i) {
		cin >> Nodes[i].first >> Nodes[i].second;
		if (Nodes[i].first == 1)
			Q.push(i);
	}
	
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		if (Nodes[u].first == 0)
			continue;
		Nodes[Nodes[u].second].second ^= u;
		Nodes[Nodes[u].second].first--;
		Aristas.push_back(pii(Nodes[u].second, u));
		if (Nodes[Nodes[u].second].first == 1)
			Q.push(Nodes[u].second);
	}
	cout << Aristas.size() << '\n';
	for (auto it : Aristas) 
		cout << it.first << ' ' << it.second << '\n';
	return 0;
}