#include <bits/stdc++.h>
using namespace std;

class AlphabetOrderDiv2 {
	private:
	public:
	
	vector< vector<int> > grafo;
	vector<char> vis;
	
	bool FoundCycle(int u) {
		vis[u] = 'G';
		for (int i = 0; i < grafo[u].size(); ++i) {
			int v = grafo[u][i];
			if (vis[v] == 'G') return true;
			if (vis[v] == 'W')
				if (FoundCycle(v)) return true;
		}
		vis[u] = 'B';
		return false;
	}
	
	bool HasCycle() {
		for (int i = 0; i < 30; ++i) vis[i] = 'W';
		for (int i = 0; i < 30; ++i)
			if (vis[i] == 'W')
				if (FoundCycle(i)) return true;
		return false;
	}
	
	string isOrdered(vector<string> words) {
		grafo = vector< vector<int> >(30);
		vis = vector<char>(30);
		for (const auto& wi : words)
			for (int i = 0; i < wi.size() - 1; ++i)
				if (wi[i] != wi[i + 1])
					grafo[wi[i] - 'a'].push_back(wi[i + 1] - 'a');
		string ans = ((HasCycle())?("Impossible"):("Possible"));
		return ans;
	}
	
};
