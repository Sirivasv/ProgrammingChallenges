#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
string wor[MAXN];
map<char, string> i_tob;
map<string, char> b_toi;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	i_tob['1'] = "*.....";
	i_tob['2'] = "*.*...";
	i_tob['3'] = "**....";
	i_tob['4'] = "**.*..";
	i_tob['5'] = "*..*..";
	i_tob['6'] = "***...";
	i_tob['7'] = "****..";
	i_tob['8'] = "*.**..";
	i_tob['9'] = ".**...";
	i_tob['0'] = ".***..";
	
	b_toi["*....."] = '1';
	b_toi["*.*..."] = '2';
	b_toi["**...."] = '3';
	b_toi["**.*.."] = '4';
	b_toi["*..*.."] = '5';
	b_toi["***..."] = '6';
	b_toi["****.."] = '7';
	b_toi["*.**.."] = '8';
	b_toi[".**..."] = '9';
	b_toi[".***.."] = '0';
	
	char opc;
	int N, c;
	string aux;
	
	while (cin >> N) {
		if (!N) break;
		cin >> opc;
		if (opc == 'S') {
			cin >> wor[0];
			for (int i = 0; i < 6; i += 2) {
				for (int j = 0; j < N; ++j) {
					if (j) cout << ' ';
					cout << i_tob[wor[0][j]][i] << i_tob[wor[0][j]][i + 1];
				}
				cout << '\n';
			}
		} else {
			for (int i = 0; i < N; ++i) 
				wor[i] = ""; 
			for (int j = 0; j < 3; ++j)
				for (int i = 0; i < N; ++i) {
					cin >> aux;
					wor[i] += aux;
				}
			for (int i = 0; i < N; ++i)
				cout << b_toi[wor[i]];
			cout << '\n';
		}
	}
	return 0;
}