#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1009;

string Inst[MAXN];
vector<int> Revby[MAXN];
set<int> Papers[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int N, K;
		cin >> K >> N;
		vector <int> many(N, 0);
		for (int i = 0; i < N; ++i) {
			Revby[i].clear();
			Papers[i].clear();
		}
			
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			Inst[i] = s;
			int tmp;
			for (int j = 0; j < K; ++j) {
				cin >> tmp;
				tmp--;
				Revby[tmp].push_back(i);
			}
			
		}
		int cnte = 0;
		for (int i = 0; i < N; ++i) {
			int f = 0;
			for (int j = 0; j < Revby[i].size(); ++j) {
				Papers[i].insert(Revby[i][j]);
				if ((Revby[i][j] == i) || (Inst[Revby[i][j]] == Inst[i]))
					f = 1;
			}
			if ((Papers[i].size() != K) || f || (Papers[i].size() != Revby[i].size()))
				cnte++;
		}
		if (cnte == 0)
			cout << "Case #" << nc << ": " << "NO PROBLEMS FOUND\n";
		else if (cnte == 1)
			cout << "Case #" << nc << ": " << "1 PROBLEM FOUND\n";
		else 
			cout << "Case #" << nc << ": " << cnte << " PROBLEMS FOUND\n";
	}
	return 0;
}