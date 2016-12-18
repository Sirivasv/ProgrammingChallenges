#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

set<int> grafo[MAXN];
vector<int> outd[MAXN];
char mtr[MAXN][MAXN];
int visto[MAXN];
char CE;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	
	int lim = s.size() - 1;
	int ok = 1;
	
	for (int i = 0; i < lim; ++i) {
		int v = s[i + 1] - 'A';
		int u = s[i] - 'A';
		grafo[u].insert(v);
		grafo[v].insert(u);
		visto[u]++;
		visto[v]++;
	}
	
	for (int i = 0; i < 26; ++i) {
		if (grafo[i].find(i) != grafo[i].end())
			ok = 0;
		if (visto[i] == 4)
			CE = (char)((char)i + 'A');
	}
	
	cout << CE << '\n';
	
	if (!ok) {
		cout << "Impossible\n";
	} else {
		int cnt = 0;
		int FE = 0;
		for (int i = 0; i < 13; ++i) {
			if (i & 1) {
				if ((s[cnt] == CE) && (FE))
				cnt++;
				else if (s[cnt] == CE)
					FE = 1;
				mtr[1][i] = s[cnt++];
				if ((s[cnt] == CE) && (FE))
					cnt++;
				else if (s[cnt] == CE)
					FE = 1;
				mtr[0][i] = s[cnt++];
			} else {
				if ((s[cnt] == CE) && (FE))
				cnt++;
				else if (s[cnt] == CE)
					FE = 1;
				mtr[0][i] = s[cnt++];
				if ((s[cnt] == CE) && (FE))
					cnt++;
				else if (s[cnt] == CE)
					FE = 1;
				mtr[1][i] = s[cnt++];
			}
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 13; ++j)
				cout << mtr[i][j];
			cout <<  '\n';
		}
	}
	
	return 0;
}