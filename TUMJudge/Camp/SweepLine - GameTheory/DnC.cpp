#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<char, pii> pci;

const int MAXL = 1009;
const int MAXN = 109;

vector<pci> S[MAXL];
int yact[MAXL];

void Limpia() {
	for (int i = 0; i < MAXL; ++i) {
		yact[i] = 0;
		S[i].clear();
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int N;
		cin >> N;
		Limpia();
		for (int i = 0; i < N; ++i) {
			int xi, yi, xj, yj;
			cin >> xi >> yi >> xj >> yj;
			if (xi == xj){ //Query
				if (yi > yj)
					swap(yi, yj);
				S[xi].push_back(pci('Q', pii(yi + 1, yj - 1)));
			}
			else {
				if (xi > xj)
					swap(xi, xj);
				S[xi + 1].push_back(pci('I', pii(yi, yj)));
				S[xj].push_back(pci('F', pii(yi, yj)));
			}
		}
		cout << "Case #" << nc << ":\n";
		set<pii> pint;
		for (int i = 0; i <= 1000; ++i) {
			if (S[i].size() == 0)
				continue;
			queue<pii> Q;
			for (int j = 0; j < S[i].size(); ++j) {
				if(S[i][j].first == 'I')
					yact[S[i][j].second.first]++;
				else if(S[i][j].first == 'F')
					yact[S[i][j].second.first]--;
				else 
					Q.push(pii(S[i][j].second.first, S[i][j].second.second));
			}
			while (!Q.empty()) {
				int ini = Q.front().first;
				int fin = Q.front().second;
				for (int k = ini; k <= fin; ++k)
					if (yact[k])
						pint.insert(pii(i, k));
				Q.pop();
			}
		}
		for (set<pii>::iterator it = pint.begin(); it!= pint.end(); it++)
			cout << (it)->first << ' ' << (it)->second << '\n';
	}
	return 0;
}