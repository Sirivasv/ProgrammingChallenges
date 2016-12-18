#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

map<string, int> btod;
map<int, string> dtob;

string srar[MAXN];
int nrar[MAXN];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	
	btod[".***.."] = 0;
	btod["*....."] = 1;
	btod["*.*..."] = 2;
	btod["**...."] = 3;
	btod["**.*.."] = 4;
	btod["*..*.."] = 5;
	btod["***..."] = 6;
	btod["****.."] = 7;
	btod["*.**.."] = 8;
	btod[".**..."] = 9;
	
	dtob[0] = ".***..";
	dtob[1] = "*.....";
	dtob[2] = "*.*...";
	dtob[3] = "**....";
	dtob[4] = "**.*..";
	dtob[5] = "*..*..";
	dtob[6] = "***...";
	dtob[7] = "****..";
	dtob[8] = "*.**..";
	dtob[9] = ".**...";
	
	int D;
	while (cin >> D) {
		if (!D)
			break;
		char op;
		cin >> op;
		if (op == 'S') {
			string s;
			cin >> s;
			for (int i = 0; i < D; ++i)
				nrar[i] = s[i] - '0';
		} else {
			for (int i = 0; i < D; ++i)
				srar[i].clear();
			for (int i = 0; i < 3; ++i) {
				string aux;
				for (int j = 0; j < D; ++j) {
					cin >> aux;
					srar[j] += aux[0];
					srar[j] += aux[1];
				}
			}
		}
		if (op == 'S') {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < D; ++j) {
					if (j)
						cout << ' ';
					cout << dtob[nrar[j]][i * 2] << dtob[nrar[j]][i * 2 + 1];
				}
				cout << '\n';
			}
		} else {
			for (int i = 0; i < D; ++i)
				cout << btod[srar[i]];
			cout << '\n';
		}
	}
	return 0;
}